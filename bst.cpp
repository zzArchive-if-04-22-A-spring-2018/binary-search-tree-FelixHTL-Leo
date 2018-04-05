/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include "general.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{
  int data;
  Node* l_subtree;
  Node* r_subtree;
};

Bst new_bst (){
  Bst bstsss = (Bst)malloc(sizeof(struct Node));
  bstsss = 0;
  return bstsss;
}

void delete_bst (Bst bst){
  if(bst == 0){
    return;
  }

  delete_bst(bst->l_subtree);
  delete_bst(bst->r_subtree);

  sfree(bst);
}

int get_depth (Bst bst){
  if(bst == 0){
    return 0;
  }
  Bst &new_bst = bst;
  int depth_r = get_depth(new_bst->r_subtree) + 1;
  int depth_l = get_depth(new_bst->l_subtree) + 1;

  if(depth_l >= depth_r){
    return depth_l;
  }
  else{
    return depth_r;
  }

  return 0;
}


void	add (Bst *bst, int value){
  Bst &new_bst = *bst;
  if(new_bst == 0)
  {
    new_bst = (Bst)malloc(sizeof(struct Node));
    new_bst->data = value;
    new_bst->r_subtree = 0;
    new_bst->l_subtree = 0;
  }
  else if(value <= new_bst->data)
  {
    add(&new_bst->l_subtree, value);

  }
  else if(value > new_bst->data)
  {
    add(&new_bst->r_subtree, value);
  }
  return;
}

int root_value (Bst bst){
  if(bst != 0){
    return bst->data;
  }
  return 0;
}

Bst left_subtree (Bst root){
  if(root == 0){
    return 0;
  }
  return root->l_subtree;
}

Bst right_subtree (Bst root){
  if(root == 0){
    return 0;
  }
  return root->r_subtree;
}

int traverse_pre_order (Bst bst, int *elements, int start){
  if(bst == 0) return 0;
  int steps_done = 0;
  elements[start] = bst->data;
  steps_done++;
  steps_done += traverse_pre_order(bst->l_subtree, elements, start + 1);
  steps_done += traverse_pre_order(bst->r_subtree, elements, start + steps_done);
  return steps_done;
}

int traverse_in_order (Bst bst, int *elements, int start){
  if(bst == 0) return 0;
  int steps_done = 0;
  steps_done += traverse_in_order(bst->l_subtree, elements, start);
  elements[start + steps_done] = bst->data;
  steps_done++;
  steps_done += traverse_in_order(bst->r_subtree, elements, start + steps_done);
  return steps_done;
}

int traverse_post_order (Bst bst, int *elements, int start){
  if(bst == 0) return 0;
  int steps_done = 0;
  steps_done += traverse_post_order(bst->l_subtree, elements, start);
  steps_done += traverse_post_order(bst->r_subtree, elements, start + steps_done);
  elements[start + steps_done] = bst->data;
  steps_done++;
  return steps_done;
}

bool are_equal (Bst bst1, Bst bst2){
  if(bst1 == bst2){
    return true;
  }
  return false;
}

void most_left_longest_branch (Bst bst, Bst *branch){
  if(bst == 0) return 0;
  add(branch)
}

int	get_number_of_subtrees (Bst bst){
  return 0;
}
