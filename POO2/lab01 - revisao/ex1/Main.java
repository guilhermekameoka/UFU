import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
			System.out.print("Digite a primeira string: ");
			String string1 = scanner.nextLine();

			System.out.print("Digite a segunda string: ");
			String string2 = scanner.nextLine();

			if (string1.endsWith(string2)) {
			    System.out.println("A primeira string termina com os caracteres da segunda string.");
			} else {
			    System.out.println("A primeira string não termina com os caracteres da segunda string.");
			}
		}
    }
}