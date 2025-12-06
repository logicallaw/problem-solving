import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();
		if (number >= 90) {
			System.out.print("A");
		} else if (number >= 80) {
			System.out.print("B");
		} else if (number >= 70 ) {
			System.out.print("C");
		} else if (number >= 60) {
			System.out.print("D");
		} else {
			System.out.print("F");
		}
		
		scanner.close();
	}
	
}
