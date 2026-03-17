import java.util.Scanner;

public class Numbers
{
// --------------------------------------------
// Reads in an array of integers, sorts them, selection sort
// then prints them in sorted order.
// --------------------------------------------
	/*public void selectionSort(int[] intList){
		int len = intList.length;

		for (int i =0; i<len; i++){

			//find minimum
			int minindex = i;

			for (int j =i; j<len;j++){
				if (intList[minindex] > intList[j]){
					minindex = j;
				}
			}
			if (intList[i] > intList[minindex]){
				int temp = intList[i];
				intList[i] = intList[minindex];
				intList[minindex] = temp;
			}
		}

	}*/
	public static void main (String[] args)
	{
		int size;
		Scanner scan = new Scanner(System.in);

		System.out.print ("\nHow many integers do you want to sort? ");
		size = scan.nextInt();

		Integer[] intList = new Integer[size];

		System.out.println ("\nEnter the numbers...");
		for (int i = 0; i < size; i++){
			intList[i] = scan.nextInt();
		}
		//java cannot compile as it has incompatible types, Comparable cannot convert to
		//int[]
		//fix is just use primitive data types in sorting

		Sorting.insertionSort(intList);
		//Sorting.selectionSort(intList);
		
		System.out.println ("\nYour numbers in sorted order...");
		
		for (int i = 0; i < size; i++)
			System.out.print(intList[i] + " ");
		System.out.println ();
		scan.close();
	}
}