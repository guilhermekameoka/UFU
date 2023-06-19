import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (var scanner = new Scanner(System.in)) {
			System.out.print("Digite uma string: ");
			String string = scanner.nextLine();

			Map<Character, Integer> charCountMap = new HashMap<>();

			for (int i = 0; i < string.length(); i++) {
			    char currentChar = string.charAt(i);
			    if (charCountMap.containsKey(currentChar)) {
			        int count = charCountMap.get(currentChar);
			        charCountMap.put(currentChar, count + 1);
			    } else {
			        charCountMap.put(currentChar, 1);
			    }
			}

			System.out.println("Caracteres e suas quantidades:");
			for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
			    System.out.println(entry.getKey() + ": " + entry.getValue());
			}
		}
    }
}