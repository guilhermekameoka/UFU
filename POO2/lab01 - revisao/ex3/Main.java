import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        int numberToGuess = random.nextInt(100) + 1;
        int guess = 0;

        try (Scanner scanner = new Scanner(System.in)) {
			while (guess != numberToGuess) {
			    System.out.print("Digite um número entre 1 e 100: ");
			    guess = scanner.nextInt();

			    if (guess < numberToGuess) {
			        System.out.println("Seu chute é muito baixo. Tente novamente.");
			    } else if (guess > numberToGuess) {
			        System.out.println("Seu chute é muito alto. Tente novamente.");
			    }
			}
		}

        System.out.println("Parabéns! Você acertou o número " + numberToGuess + ".");
    }
}