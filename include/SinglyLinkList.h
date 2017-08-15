#ifndef SINGLYLINKLIST_H
#define SINGLYLINKLIST_H

#include <iostream>
template <class T>
class SinglyNode {

public:

    SinglyNode() {

        this->next = 0;
    }

    SinglyNode(const T& value, SinglyNode* prtnext = 0) : info(value), next(prtnext) {

    }

    T info;
    SinglyNode *next;

};


template <class T>
class SinglyLinkList {

public:

        SinglyLinkList();
        SinglyLinkList(const SinglyLinkList&);
        virtual ~SinglyLinkList();
        SinglyLinkList operator =(const SinglyLinkList&);
        void push_back(T&);
        void push_front(T&);
        void pop_back();
        void pop_front();
        void insert(unsigned, T&);
        void erase(unsigned);
        unsigned size();
        void clear();
        T& front();
        T& back();
        bool is_empty();
        void sort();
//        void unique();

protected:

private:

    SinglyNode<T> *head, *tail;

};

template <class T>
SinglyLinkList<T>::SinglyLinkList() {

    head = 0;
    tail = 0;

}

template <class T>
SinglyLinkList<T>::SinglyLinkList(const SinglyLinkList<T>& other) {

    head = 0;
    tail = 0;

    if(other.head != 0) {

        SinglyNode<T>* pred = other.head;

        while(pred != 0) {

            this->push_front(pred->info);
            pred = pred->next;

        }
    }

}

template <class T>
SinglyLinkList<T>::~SinglyLinkList() {

    this->clear();

}

template <class T>
SinglyLinkList<T> SinglyLinkList<T>::operator =(const SinglyLinkList<T>& other) {

    if(!this->is_empty()) this->clear();
    if(other.head == 0) return *this;

    SinglyNode<T>* pred = other.head;

    while(pred != 0) {

        this->push_front(pred->info);
        pred = pred->next;

    }

    return *this;
}

template <class T>
void SinglyLinkList<T>::push_back(T& value) {

    if(tail != 0){

        tail->next = new SinglyNode<T>(value);
        tail = tail->next;

    } else {

        head = tail = new SinglyNode<T>(value);
    }
}

template <class T>
void SinglyLinkList<T>::push_front(T& value) {

    head = new SinglyNode<T>(value, head);

    if(tail == 0) tail = head;

}

template <class T>
void SinglyLinkList<T>::pop_back() {

    if(!this->is_empty()) {

        if(head = tail) {

            delete head;
            head = tail = 0;

        } else {

            SinglyNode<T>* prev = head;

            while(prev->next != tail) {

                prev = prev->next;
            }

            delete tail;
            tail = prev;
            tail->next = 0;

        }
    }

}

template <class T>
void SinglyLinkList<T>::pop_front() {

    if(!this->is_empty()) {

        if(head = tail) {

            delete head;
            head = tail = 0;

        } else {

            SinglyNode<T> *p = head;
            head = head->next;
            delete p;

        }
    }

}


template <class T>
void SinglyLinkList<T>::insert(unsigned position, T& value) {

    if(position == 1) {

        head = new SinglyNode<T>(value, head);

    } else {

        SinglyNode<T> *prev = head, *nxt = head->next;
        unsigned k = 1;

        while(nxt != 0 && k < position) {

            prev = prev->next;
            nxt = nxt->next;
            k++;
        }

        if(prev == tail) {

            tail->next = new SinglyNode<T>(value);
            tail = tail->next;

        } else {

            prev->next = new SinglyNode<T>(value, nxt);

        }


    }
}

template <class T>
void SinglyLinkList<T>::erase(unsigned position) {

    if(!this->is_empty()) {
        if(position == 1) {

            SinglyNode<T> *p = head;
            if(head == tail) {

                head = tail = 0;

            } else {

                head = head->next;

            }

            delete p;

        } else {

            SinglyNode<T> *prev = head, *nxt = head->next;
            unsigned k = 1;
            while(nxt != 0 && k < position) {

                prev = prev->next;
                nxt = nxt->next;
                k++;
            }
            if(nxt != 0) {

                prev->next = nxt->next;
                if(nxt == tail) tail  = prev;
                delete nxt;

            }

        }
    }
}

template <class T>
unsigned SinglyLinkList<T>::size() {

    if(this->is_empty()) return 0;

    SinglyNode<T> *p = head;
    unsigned k = 1;

    while(p != tail) {

        p = p->next;
        k++;
    }

    return k;

}

template <class T>
void SinglyLinkList<T>::clear() {

    if(!this->is_empty()) {

        SinglyNode<T> *p;

        while(head != 0) {

            p = head;
            head = head->next;
            delete p;

        }

        tail = 0;

    }

}

template <class T>
T& SinglyLinkList<T>::front() {

    return this->head->info;

}

template <class T>
T& SinglyLinkList<T>::back() {

    return this->tail->info;

}

template <class T>
bool SinglyLinkList<T>::is_empty() {

    if(this->head == 0 && this->tail == 0) return true;
    return false;
}


template <class T>
void SinglyLinkList<T>::sort() {

    if(head == tail) return;

    SinglyNode<T>* pred = head;

    while(pred != tail) {

        SinglyNode<T>* nxt = pred->next;

        while(nxt != 0) {

            if(pred->info > nxt->info) {

                // swap a <-----> b
                pred->info += nxt->info;
                nxt->info = pred->info - nxt->info;
                pred->info -= nxt->info;
            }

            nxt = nxt->next;

        }

        pred = pred->next;

    }

}

#endif // SINGLYLINKLIST_H
