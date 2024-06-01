#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* mirror(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    else {
        struct Node* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}


void Seviye_yazdir(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[1000];
    int on = 0, arka = 0;
    queue[arka] = root;
    arka++;
    int seviye = 1;
    int say = 1;

    while (on < arka) {
        printf("Seviye %d: ", seviye);
        int seviye_say = say;
        say = 0;

        while (seviye_say > 0) {
            struct Node* node = queue[on];
            if (node != NULL) {
                printf("%d ", node->value);
                say += 2;
                queue[arka] = node->left;
                arka++;
                queue[arka] = node->right;
                arka++;
            }
            else {
                printf("bos ");
            }
            on++;
            seviye_say--;
        }

        printf("\n");
        seviye++;
    }
}

int main() {
    struct Node* root = NULL;
    int arr[] = {40, 70, 50, 30, 25, 75, 65, 5,99,35,28,100,1,17,88};
	int i = 0;
	
  while (arr[i] != 0) {
    root = insert(root, arr[i]);
    i++;
}


    printf("Listeleme:\n");
    Seviye_yazdir(root);
    
    printf("\nKok dugume gore simetrigi:\n");
    root = mirror(root);
    Seviye_yazdir(root);

    return 0;
}

