// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <memory>

#include "./Linked_list_prototype.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

// @include
shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>>& L) {
  if (!L) {
    return L;
  }

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto now = L;
  while (now && now->next) {
    if (now->data > now->next->data) {
      auto target = now->next, pre = dummy_head;
      while (pre->next->data < target->data) {
        pre = pre->next;
      }
      auto temp = pre->next;
      pre->next = target;
      now->next = target->next;
      target->next = temp;
    } else {
      now = now->next;
    }
  }
  return dummy_head->next;
}
// @exclude

int main(int argc, char** argv) {
  shared_ptr<ListNode<int>> L;
  L = make_shared<ListNode<int>>(ListNode<int>{
      1, make_shared<ListNode<int>>(ListNode<int>{
             4, make_shared<ListNode<int>>(ListNode<int>{
                    3, make_shared<ListNode<int>>(ListNode<int>{
                           2, make_shared<ListNode<int>>(
                                  ListNode<int>{5, nullptr})})})})});
  auto result = InsertionSort(L);
  shared_ptr<ListNode<int>> pre = nullptr;
  while (result) {
    assert(!pre || pre->data <= result->data);
    pre = result;
    cout << result->data << endl;
    result = result->next;
  }
  return 0;
}
