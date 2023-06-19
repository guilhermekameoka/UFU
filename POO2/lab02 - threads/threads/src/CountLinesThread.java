import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayList;
import java.util.List;

public class CountLinesThread extends Thread {

    private final File file;
    private int count;

    public CountLinesThread(File file) {
        this.file = file;
    }

    public int getCount() {
        return count;
    }

    @Override
    public void run() {
        try (LineNumberReader reader = new LineNumberReader(new FileReader(file))) {
            // Usando LineNumberReader para contar as linhas do arquivo
            while (reader.readLine() != null) {
                // Lê as linhas sem incrementar o contador manualmente
            }
            count = reader.getLineNumber();
        } catch (IOException e) {
            // Exibindo mensagem de erro caso não seja possível ler o arquivo
            System.err.println("Erro ao ler o arquivo: " + file.getName());
            e.printStackTrace();
        }
    }

    // Método para listar todos os arquivos de uma pasta com uma determinada extensão
    public static List<File> listFilesWithExtension(String folderPath, String extension) {
        List<File> files = new ArrayList<>();
        File folder = new File(folderPath);
        File[] allFiles = folder.listFiles();
        for (File file : allFiles) {
            if (file.isFile() && file.getName().endsWith(extension)) {
                files.add(file);
            }
        }
        return files;
    }

    // Método para contar o total de linhas de vários arquivos em paralelo
    public static int countTotalLines(List<File> files) {
        int totalLines = 0;
        for (File file : files) {
            try (LineNumberReader reader = new LineNumberReader(new FileReader(file))) {
                // Usando LineNumberReader para contar as linhas do arquivo
                while (reader.readLine() != null) {
                    // Lê as linhas sem incrementar o contador manualmente
                }
                totalLines += reader.getLineNumber();
            } catch (IOException e) {
                // Exibindo mensagem de erro caso não seja possível ler o arquivo
                System.err.println("Erro ao ler o arquivo: " + file.getName());
                e.printStackTrace();
            }
        }
        return totalLines;
    }

    public static void main(String[] args) {
        String folderPath = "C:\\Users\\grkam\\OneDrive\\Área de Trabalho\\lab02\\txt";
        String extension = ".txt";
        long startTime = System.currentTimeMillis();

        // Listando todos os arquivos com a extensão ".txt" na pasta especificada
        List<File> files = listFilesWithExtension(folderPath, extension);
        // Contando o total de linhas de todos os arquivos sequencialmente
        int totalLines = countTotalLines(files);

        long endTime = System.currentTimeMillis();

        System.out.println("Total de linhas lidas: " + totalLines);
        System.out.println("Tempo gasto (ms): " + (endTime - startTime));
    }
}

/* SPECS DO PC:
 * PROCESSADOR I7 9700K
 * 32GB RAM
 * Total de linhas lidas: 267462730
Tempo gasto (ms): 10022

CONCLUSÃO:
Os resultados do CountLineThread se assemelham ao CountLinesSequential, pois o desempenho de 1 thread é similar à leitura sequencial dos arquivos, pois como só há uma thread trabalhando, ela terá
que fazer a leitura 1 a 1, e isso demanda tempo. Já o desempenho do ThreadPool é bem melhor, pois são instanciadas várias threads, lendo vários arquivos por fez.
 */
