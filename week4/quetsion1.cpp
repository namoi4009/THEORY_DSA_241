void prev() {
    if (!curr->prev) return;
    this->curr = curr->prev;
}