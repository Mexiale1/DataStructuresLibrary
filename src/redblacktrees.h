#pragma once

#include "../include/sset.h"
#include <stddef.h>
#include <iostream>

template <typename T> class RBTreeSet : public SortedSet<T> {
private:
    const int RED = 0;
    const int BLACK = 1;

    struct Node {
        T x;
        int color;
        Node *left, *right, *parent;

        Node(const T& val, int c) {
            x = val;
            color = c;
            left = right = parent = nullptr;
        }
    };

    Node* root;
    Node* NIL; // sentinel
    size_t n;

    int comp2(const T& a, const T& b) const {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

public:
    RBTreeSet() {
        NIL = new Node(T(), BLACK);
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
        n = 0;
    }

    size_t size() const override {
        return n;
    }

    void rotateLeft(Node* u) {
        Node* w = u->right;
        u->right = w->left;

        if (w->left != NIL)
            w->left->parent = u;

        w->parent = u->parent;

        if (u->parent == NIL)
            root = w;
        else if (u == u->parent->left)
            u->parent->left = w;
        else
            u->parent->right = w;

        w->left = u;
        u->parent = w;
    }

    void rotateRight(Node* u) {
        Node* w = u->left;
        u->left = w->right;

        if (w->right != NIL)
            w->right->parent = u;

        w->parent = u->parent;

        if (u->parent == NIL)
            root = w;
        else if (u == u->parent->left)
            u->parent->left = w;
        else
            u->parent->right = w;

        w->right = u;
        u->parent = w;
    }

    bool add(const T& x) override {
        Node* u = new Node(x, RED);
        u->left = u->right = u->parent = NIL;

        Node* cur = root;
        Node* parent = NIL;

        while (cur != NIL) {
            parent = cur;
            int c = comp2(x, cur->x);

            if (c < 0)
                cur = cur->left;
            else if (c > 0)
                cur = cur->right;
            else {
                delete u;
                return false;
            }
        }

        u->parent = parent;

        if (parent == NIL)
            root = u;
        else if (comp2(x, parent->x) < 0)
            parent->left = u;
        else
            parent->right = u;

        addFixup(u);
        n++;
        return true;
    }

    void addFixup(Node* u) {
        while (u->parent->color == RED) {
            if (u->parent == u->parent->parent->left) {
                Node* uncle = u->parent->parent->right;

                if (uncle->color == RED) {
                    u->parent->color = BLACK;
                    uncle->color = BLACK;
                    u->parent->parent->color = RED;
                    u = u->parent->parent;
                } else {
                    if (u == u->parent->right) {
                        u = u->parent;
                        rotateLeft(u);
                    }

                    u->parent->color = BLACK;
                    u->parent->parent->color = RED;
                    rotateRight(u->parent->parent);
                }
            } else {
                Node* uncle = u->parent->parent->left;

                if (uncle->color == RED) {
                    u->parent->color = BLACK;
                    uncle->color = BLACK;
                    u->parent->parent->color = RED;
                    u = u->parent->parent;
                } else {
                    if (u == u->parent->left) {
                        u = u->parent;
                        rotateRight(u);
                    }

                    u->parent->color = BLACK;
                    u->parent->parent->color = RED;
                    rotateLeft(u->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    T find(const T& x) const override {
        Node* cur = root;

        while (cur != NIL) {
            int c = comp2(x, cur->x);

            if (c == 0)
                return cur->x;
            else if (c < 0)
                cur = cur->left;
            else
                cur = cur->right;
        }

        return T();
    }

    Node* findNode(const T& x) const {
        Node* cur = root;

        while (cur != NIL) {
            int c = comp2(x, cur->x);

            if (c == 0)
                return cur;
            else if (c < 0)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return NIL;
    }

    Node* findMin(Node* u) {
        while (u->left != NIL)
            u = u->left;
        return u;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == NIL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        v->parent = u->parent;
    }

    T remove(const T& x) override {
        Node* z = findNode(x);
        if (z == NIL)
            return T();

        Node* y = z;
        Node* xNode;
        int yOriginalColor = y->color;

        if (z->left == NIL) {
            xNode = z->right;
            transplant(z, z->right);
        }
        else if (z->right == NIL) {
            xNode = z->left;
            transplant(z, z->left);
        }
        else {
            y = findMin(z->right);
            yOriginalColor = y->color;
            xNode = y->right;

            if (y->parent == z) {
                xNode->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;
        n--;

        if (yOriginalColor == BLACK)
            removeFixup(xNode);

        return x;
    }

    void removeFixup(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }

                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void printHelper(Node* node, const std::string& indent, bool isLeft) const {
        if (node == NIL) return;

        std::cout << indent;

        if (node != root) {
            if (isLeft) {
                std::cout << "|-- ";  // left child
            } else {
                std::cout << "\\-- "; // right child
            }
        }

        std::cout << node->x;
        if (node->color == RED)
            std::cout << "(R)";
        else
            std::cout << "(B)";
        std::cout << "\n";

        std::string newIndent = indent;
        if (node != root) {
            if (isLeft) newIndent += "|   ";
            else newIndent += "    ";
        }

        printHelper(node->left, newIndent, true);
        printHelper(node->right, newIndent, false);
    }

    void printTree() const {
        std::cout << "\nTree Structure:\n";
        if (root == NIL) {
            std::cout << "(empty)\n";
            return;
        }
        printHelper(root, "", false);
        std::cout << "\n";
    }
    void compare(T &x, T &y) override { }
};
