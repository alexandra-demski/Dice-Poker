/*
Fichier contenant les fonctions liées à un tri "bubble sort"
*/

void swap(int *xp, int *yp){
    /*
    * Echange deux cellules d'un tableau
    * @param les cellules à échanger
    * @return void
    */
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int size){
    /*
    * Tri un tableau en implémentant le bubble sort
    * @param tableau à trier et sa taille
    * @return void
    */
    for (int i=0; i<size-1; i++)      

        for (int j=0; j<size-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}