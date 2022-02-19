// time complexity analysis: if we have 'n' nodes and each n node have m childrens. time complexity will be O(m + 2m+ 3m + ....nm) * n(to traverse the straight line of linked
//list. so we can say time complexity is O(n^2*m) and space is O(1)
Node* merge_linked_list(Node* A, Node* B) {
    Node* temp = new Node(0);
  // it will be head of the merged linked list
    Node* head = temp;
    while (A && B) {
        if (A->data < B->data) {
            temp->bottom = A;
            temp = temp->bottom;
            A = A->bottom;
        }
        else {
            temp->bottom = B;
            temp = temp->bottom;
            B = B->bottom;
        }
    }
    if (A) {
        temp->bottom = A;
    }
    else if (B) {
        temp->bottom = B;
    }
    return head->bottom;
}

Node* flatten(Node* root)
{
    // Your code here
    if (root == nullptr || root->next == nullptr) {
        return root;
    }
    root->next = flatten(root->next);
    Node* new_node = merge_linked_list(root, root->next);
    return new_node;
}
