void mirror(Node* node) {
        if(!node || (!node->left && !node->right)) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
}