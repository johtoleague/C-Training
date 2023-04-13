#include <stdio.h>
#include <stdlib.h>

struct bookInfo {
    char title[40];
    char author[25];
    float price;
    int pages;
};

main()
{
    int ctr;
    struct bookInfo * books[3];

    //get the info about each book from the user

    for (ctr = 0; ctr < 3; ctr++)
    {   
        books[ctr] = (struct bookInfo*)malloc(sizeof(struct bookInfo));

        printf("What is the name of the book #%d?\n", (ctr+1));
        gets(books[ctr]->title);
        puts("Who is the author? ");
        gets(books[ctr]->author);
        puts("How much did the book cost? ");
        scanf("%f", &books[ctr]->price);
        puts ("How many pages in the book? ");
        scanf(" %d", &books[ctr]->pages);
        getchar();//clears last newline for next loop
    }

    printf("\n\nHere is the collection of books:\n");
    for (ctr = 0; ctr < 3; ctr++)
    {
        printf("#%d: %s by %s", ctr+1, books[ctr]->title, books[ctr]->author);

        printf("\nIt is %d pages and costs $%.2f", books[ctr]->pages, books[ctr]->price);

        printf("\n\n");

    }
    return(0);

}