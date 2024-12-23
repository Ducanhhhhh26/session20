#include <stdio.h>
#include <string.h>

struct Book {
    char bookId[20]; 
    char title[100]; 
    char author[50];
    float price; 
    char category[50];
};

void inputBook(struct Book books[], int *count) {
    printf("nhap ma sach: ");
    fgets(books[*count].bookId, sizeof(books[*count].bookId), stdin);
    books[*count].bookId[strcspn(books[*count].bookId, "\n")] = 0;
    
    printf("Ten sach: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0;
    
    printf("Ten tac gia: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0;
    
    printf("Nhap gia: ");
    scanf("%f", &books[*count].price);
    getchar();
    
    printf("nhap the loai: ");
    fgets(books[*count].category, sizeof(books[*count].category), stdin);
    books[*count].category[strcspn(books[*count].category, "\n")] = 0;
    
    (*count)++;
}

void displayBooks(struct Book books[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Ma sach: %s\n", books[i].bookId);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
        printf("The loai : %s\n\n", books[i].category);
    }
}

void addBookAtPosition(struct Book books[], int *count) {
    int pos;
    printf("Nhap vi tri can them: ");
    scanf("%d", &pos);
    getchar();
    
    if (pos < 1 || pos > *count + 1) {
        printf("V? trí không h?p l?!\n");
    } else {
        for (int i = *count; i >= pos; i--) {
            books[i] = books[i - 1];
        }
        inputBook(books, &pos);
        (*count)++;
    }
}

void deleteBookById(struct Book books[], int *count) {
    char bookId[20];
    printf("nha ma sach can xoa: ");
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].bookId, bookId) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma sach\n");
    }
}

void updateBookById(struct Book books[], int count) {
    char bookId[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].bookId, bookId) == 0) {
            found = 1;
            printf("Nhap ten sach moi: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = 0;

            printf("nhap tac gia moi: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;

            printf("Nhap gia moi: ");
            scanf("%f", &books[i].price);
            getchar(); 

            printf("Nhap the loai moi: ");
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = 0;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma sach\n");
    }
}

void sortBooksByPrice(struct Book books[], int count, int pick) {
    struct Book temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((pick == 1 && books[i].price > books[j].price) || 
                (pick == 2 && books[i].price < books[j].price)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void searchBookByTitle(struct Book books[], int count) {
    char title[100];
    printf("Nhap ten sach can tim kiem: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("Ma sach: %s\n", books[i].bookId);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia: %.2f\n", books[i].price);
            printf("The loai: %s\n\n", books[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay ten sach?!\n");
    }
}

int main() {
    struct Book books[100];
    int count = 0;
    int choice, pick;

    do {
        printf("\n1. Them sach\n2. Hien thi sach\n3. Them sach vao vi tri\n4. Xoa sach theo ma \n5. Cap nhat sach theo ma\n6. Sap xep sach theo gia\n7. Tim sach theo tieu de\n8. Thooat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                addBookAtPosition(books, &count);
                break;
            case 4:
                deleteBookById(books, &count);
                break;
            case 5:
                updateBookById(books, count);
                break;
            case 6:
                printf("Nhap 1 de tang dan, 2 de giam dan: ");
                scanf("%d", &pick);
                getchar();
                sortBooksByPrice(books, count, pick);
                break;
            case 7:
                searchBookByTitle(books, count);
                break;
            case 8:
                printf("Ban da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le vui long chon lai\n");
        }
    } while (choice != 8);

    return 0;
}

