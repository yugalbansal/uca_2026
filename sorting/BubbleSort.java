import java.util.Random;

class BubbleSort{
    public static void bubbleSort(int[] arr){
	int n = arr.length;
	for (int i = 0; i < n - 1; i++) {
	    for ( int j = 0 ; j < n - i - 1; j++ ) {
		if ( arr[j] > arr[j+1] ) {
		    int temp = arr[j];
		    arr[j] = arr[j+1];
		    arr[j+1] = temp;
		}
	    }
	}
    }

    public static void generateNumbers(int[] arr){
	Random rand = new Random();
	for ( int i = 0; i < arr.length; i++){
	    arr[i] = rand.nextInt(10000);
	}
    }

    public static void main(String[] args){
	int[] arr1 = new int[40000];
	int[] arr2 = new int[80000];
	generateNumbers(arr1);
	long start1 = System.nanoTime();
	bubbleSort(arr1);
	long end1 = System.nanoTime();
	double time1 = (end1 - start1)/1000000000.0;
	generateNumbers(arr2);
	long start2 = System.nanoTime();
	bubbleSort(arr2);
	long end2 = System.nanoTime();
	double time2 = (end2 - start2)/1000000000.0;
	System.out.print(time2/time1);
    }
}
