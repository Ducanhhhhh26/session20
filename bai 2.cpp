#include <stdio.h>
#include <string.h>

typedef struct {
    char productID[20];
    char productName[100];
    float importPrice;
    float salePrice;
    int quantity;
} Product;

Product products[100];
int productCount = 0;
float revenue = 0;

void inputProduct();
void displayProducts();
void addProduct();
void updateProduct();
void sortProductsByPrice(int order);

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5: {
                int order;
                printf("Nhap 1 de sap xep tang dan, 2 de sap xep giam dan: ");
                scanf("%d", &order);
                getchar();
                sortProductsByPrice(order);
                break;
            }
            case 6:
                printf("Dang thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}

void inputProduct() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        Product p;
        printf("Nhap thong tin san pham thu %d\n", i + 1);

        printf("Ma san pham: ");
        fgets(p.productID, sizeof(p.productID), stdin);
        p.productID[strcspn(p.productID, "\n")] = 0;

        printf("Ten san pham: ");
        fgets(p.productName, sizeof(p.productName), stdin);
        p.productName[strcspn(p.productName, "\n")] = 0;

        printf("Gia nhap: ");
        scanf("%f", &p.importPrice);
        getchar();

        printf("Gia ban: ");
        scanf("%f", &p.salePrice);
        getchar();

        printf("So luong: ");
        scanf("%d", &p.quantity);
        getchar();

        revenue -= p.importPrice * p.quantity;

        int found = 0;
        for (int j = 0; j < productCount; j++) {
            if (strcmp(products[j].productID, p.productID) == 0) {
                products[j].quantity += p.quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            products[productCount++] = p;
        }
    }
}

void displayProducts() {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Ma san pham: %s\n", products[i].productID);
        printf("Ten san pham: %s\n", products[i].productName);
        printf("Gia nhap: %.2f\n", products[i].importPrice);
        printf("Gia ban: %.2f\n", products[i].salePrice);
        printf("So luong: %d\n\n", products[i].quantity);
    }
}

void addProduct() {
    Product p;
    printf("Nhap thong tin san pham moi\n");

    printf("Ma san pham: ");
    fgets(p.productID, sizeof(p.productID), stdin);
    p.productID[strcspn(p.productID, "\n")] = 0;

    printf("Ten san pham: ");
    fgets(p.productName, sizeof(p.productName), stdin);
    p.productName[strcspn(p.productName, "\n")] = 0;

    printf("Gia nhap: ");
    scanf("%f", &p.importPrice);
    getchar();

    printf("Gia ban: ");
    scanf("%f", &p.salePrice);
    getchar();

    printf("So luong: ");
    scanf("%d", &p.quantity);
    getchar();

    revenue -= p.importPrice * p.quantity;

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, p.productID) == 0) {
            products[i].quantity += p.quantity;
            found = 1;
            break;
        }
    }
    if (!found) {
        products[productCount++] = p;
    }
}

void updateProduct() {
    char productID[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(productID, sizeof(productID), stdin);
    productID[strcspn(productID, "\n")] = 0;

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, productID) == 0) {
            printf("Nhap ten san pham moi: ");
            fgets(products[i].productName, sizeof(products[i].productName), stdin);
            products[i].productName[strcspn(products[i].productName, "\n")] = 0;

            printf("Nhap gia nhap moi: ");
            scanf("%f", &products[i].importPrice);
            getchar();

            printf("Nhap gia ban moi: ");
            scanf("%f", &products[i].salePrice);
            getchar();

            printf("Nhap so luong moi: ");
            scanf("%d", &products[i].quantity);
            getchar();
            break;
        }
    }
}

void sortProductsByPrice(int order) {
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if ((order == 1 && products[i].salePrice > products[j].salePrice) ||
                (order == 2 && products[i].salePrice < products[j].salePrice)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("San pham da duoc sap xep.\n");
}



