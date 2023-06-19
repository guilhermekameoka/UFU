import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ThreadPool {

    public static void main(String[] args) throws InterruptedException {
        String folderPath = "C:\\Users\\grkam\\OneDrive\\Área de Trabalho\\lab02\\txt";
        String extension = ".txt";
        int numThreads = 100;

        long startTime = System.currentTimeMillis();

        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(numThreads);

        try (Stream<Path> walk = Files.walk(Paths.get(folderPath))) {
            List<File> files = walk.filter(Files::isRegularFile)
                                   .map(Path::toFile)
                                   .filter(f -> f.getName().endsWith(extension))
                                   .collect(Collectors.toList());

            for (File file : files) {
                Task task = new Task(file, extension);
                System.out.println("Criada : " + task.getName());
                executor.execute(task);
            }
        } catch (IOException e) {
            System.err.println("Erro ao listar arquivos no diretório: " + folderPath);
            e.printStackTrace();
        }

        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);

        int totalLines = Task.getTotalLines();

        long endTime = System.currentTimeMillis();
        long totalTime = endTime - startTime;

        System.out.println("Total de linhas lidas: " + totalLines);
        System.out.println("Tempo gasto (ms): " + totalTime);
    }
}

class Task implements Runnable {
    private static int totalLines = 0;

    private File file;
    private String extension;

    public Task(File file, String extension) {
        this.file = file;
        this.extension = extension;
    }

    public void run() {
        try {
            long count = Files.lines(file.toPath()).count();
            synchronized (Task.class) {
                totalLines += count;
            }
            System.out.println(file.getName() + ": " + count);
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + file.getName());
            e.printStackTrace();
        }
    }

    public String getName() {
        return file.getName();
    }

    public static int getTotalLines() {
        return totalLines;
    }
}

/*Tempo gasto (ms): 2206
 * I7 9700K
 * 
 * CONCLUSÃO:
Os resultados do CountLineThread se assemelham ao CountLinesSequential, pois o desempenho de 1 thread é similar à leitura sequencial dos arquivos, pois como só há uma thread trabalhando, ela terá
que fazer a leitura 1 a 1, e isso demanda tempo. Já o desempenho do ThreadPool é bem melhor, pois são instanciadas várias threads, lendo vários arquivos por fez.
 */
