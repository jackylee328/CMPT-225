/*
 * BST.cpp
 *
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#include "BST.h"
#include <cstddef>
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

template <class ElementType>
int BST<ElementType>::nodeCountR(BSTNode<ElementType>* current) const{
	int count = 1;
	if (current->hasLeft()){
		count += nodeCountR(current->left);
	}
	if (current->hasRight()){
		count += nodeCountR(current->right);
	}
	return count;
}

template <class ElementType>
int BST<ElementType>::nodeCount() const{
	if (elementCount == 0){
		return 0;
	}
	return nodeCountR(root);
}

template <class ElementType>
ElementType& BST<ElementType>::minR(BSTNode<ElementType>* current) const{
	if (current->hasLeft()){
		return minR(current->left);
	}
	return current->element;
}

template <class ElementType>
ElementType& BST<ElementType>::min() const throw(ElementDoesNotExistInBSTException){
	if (elementCount == 0){
		throw ElementDoesNotExistInBSTException("min does not exist");
	}
	else{
		return minR(root);
	}
}

template <class ElementType>
ElementType& BST<ElementType>::maxR(BSTNode<ElementType>* current) const{
	if (current->hasRight()){
		return maxR(current->right);
	}
	return current->element;
}

template <class ElementType>
ElementType& BST<ElementType>::max() const throw(ElementDoesNotExistInBSTException){
	if (elementCount == 0){
		throw ElementDoesNotExistInBSTException("max does not exist");
	}
	else{
		return maxR(root);
	}
}

template <class ElementType>
int BST<ElementType>::duplicateR(const ElementType& targetElement, BSTNode<ElementType> * current){
	int count = 0;
	if (current->element == targetElement){
		count++;
	}
	if (current->hasLeft()){
		count += duplicateR(targetElement, current->left);
	}
	if (current->hasRight()){
		count += duplicateR(targetElement, current->right);
	}
	return count;
}

template <class ElementType>
int BST<ElementType>::duplicate(const ElementType& targetElement){
	if (elementCount == 0){
		return 0;
	}
	return duplicateR(targetElement, root);
}

template <class ElementType>
BSTNode<ElementType>* BST<ElementType>::removeR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException){
	if (current->element == targetElement){
    	// Case 1: No Child
    	if(current->isLeaf()){
      		delete current;
			current = NULL;
    	// Case 2: one child
		}
		else if(!current->hasLeft()){
    		BSTNode<ElementType>* temp = current;
      		current = current->right;
	    	delete temp;
    	}
		else if(!current->hasRight()){
      		BSTNode<ElementType>* temp = current;
      		current = current->left;
      		delete temp;
    	}
		else{
      		ElementType temp = minR(current->right);
      		current->element = temp;
      		current->right = removeR(temp, current->right);
    	}
  	}
	else if (current->element < targetElement){
		if (current->hasRight()){
			removeR(targetElement, current->right);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
	else{
		if (current->hasLeft()){
			removeR(targetElement, current->left);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
	return current;
}

template <class ElementType>
void BST<ElementType>::remove(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException){
	if (elementCount == 0){
		throw ElementDoesNotExistInBSTException("element does not exist");
	}
	removeR(targetElement, root);
}

template <class ElementType>
bool BST<ElementType>::insertR(const ElementType& element, BSTNode<ElementType>* current) throw(ElementAlreadyExistsInBSTException){
	if (element == current->element){
		throw ElementAlreadyExistsInBSTException("element already exists");
		return false;
	}
	else if (current->element < element){
		if (current->hasRight()){
			return insertR(element, current->right);
		}
		else{
			BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
			current->right = newNode;
			return true;
		}
	}
	else{
		if (current->hasLeft()){
			return insertR(element, current->left);
		}
		else{
			BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
			current->left = newNode;
			return true;
		}
	}
}

template <class ElementType>
ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException){
	if (targetElement == current->element){
		return current->element;
	}
	else if (current->element < targetElement){
		if (current->hasRight()){
			return retrieveR(targetElement, current->right);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
	else{
		if (current->hasLeft()){
			return retrieveR(targetElement, current->left);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
}

template <class ElementType>
void BST<ElementType>::traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const{
	if (current->hasLeft()){
		traverseInOrderR(visit, current->left);
	}
	visit(current->element);
	if (current->hasRight()){
		traverseInOrderR(visit, current->right);
	}
}

template <class ElementType>
BST<ElementType>::BST(){                               // Default constructor
	BSTNode<ElementType>* newNode = new BSTNode<ElementType>;
	root = newNode;
	elementCount = 0;
}

template <class ElementType>
BST<ElementType>::BST(ElementType& element){           // Parameterized constructor
	BSTNode<ElementType> newNode = BSTNode<ElementType>(element);
	root = newNode;
	elementCount = 1;
}

template <class ElementType>
BST<ElementType>::BST(const BST<ElementType>& aBST){   // Copy constructor

}

template <class ElementType>
BST<ElementType>::~BST(){                              // Destructor

}

 // Time efficiency: O(1)
template <class ElementType>
int BST<ElementType>::getElementCount() const{
	return elementCount;
}

// Time efficiency: O(log2 n)
template <class ElementType>
void BST<ElementType>::insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException){
	if (elementCount == 0){
		BSTNode<ElementType>* newNode = new BSTNode<ElementType>(newElement);
		root = newNode;
		elementCount++;
	}
	else if (root->element == newElement){
		throw ElementAlreadyExistsInBSTException("element already exists");
	}
	else{
		bool insertSuccessful = insertR(newElement, root);
		if (insertSuccessful){
			elementCount++;
		}
	}
}

// Time efficiency: O(log2 n)
template <class ElementType>
ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException){
	if (elementCount == 0){
		throw ElementDoesNotExistInBSTException("element does not exist");
	}
	else if (root->element == targetElement){
		return root->element;
	}
	else{
		return retrieveR(targetElement, root);
	}
}

// Time efficiency: O(n)
template <class ElementType>
void BST<ElementType>::traverseInOrder(void visit(ElementType&)) const{
	if (elementCount != 0){
		traverseInOrderR(visit, root);
	}
}
