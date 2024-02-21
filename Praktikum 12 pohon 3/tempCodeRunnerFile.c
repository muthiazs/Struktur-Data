    printf("\nMencetak pohon A secara BFS : \t");
    List1 Lbfs;
    Lbfs = linearBreadthFS(A);
    PrintList(Lbfs);
    printf("\nMenampilkan jalur dari akar P (M) ke H : \t");
    printPathX(A,'H');