
import java.util.Scanner;

class P2   // class name - file name must be same as class name
{
	// for a start, use "public static" when defining your methods (function)
	// "public static" make the method global just like 'C'
	// when you have learnt OO, you will use LESS of static
   // entry into a Java program - in 'C' is int main()
   public static void main(String[] args)
   {
		Scanner myObj = new Scanner(System.in);

		System.out.print("Salary: ");
		int ranges = myObj.nextInt();
        System.out.print("Merit: ");
        int merit = myObj.nextInt();
        if (899 >= ranges && 500 <= ranges){
            if (ranges > 799){
                System.out.format("Salary: %d, merit: %d -Grade A", ranges, merit);
            }

            else if (799 >= ranges && ranges >= 700){
                if (merit < 20){
                    System.out.format("Salary: %d, merit: %d -Grade B", ranges, merit);
                }else{
                    System.out.format("Salary: %d, merit: %d -Grade A", ranges, merit);
                }
            }
            else if (649 >= ranges && ranges >= 600){
                if (merit > 10){
                    System.out.format("Salary: %d, merit: %d -Grade B", ranges, merit);
                }else{
                    System.out.format("Salary: %d, merit: %d -Grade C", ranges, merit);
                }
            }
            else{
                System.out.format("Salary: %d, merit: %d -Grade C", ranges, merit);
            }

		myObj.close();
        }
   }
}