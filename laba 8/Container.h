#pragma once
#include <iostream>

using namespace std;

class MyException : public logic_error
{
public:
    explicit MyException(string message) : logic_error(message) {}
};
class NotFound : public MyException
{
public:
    explicit NotFound() : MyException("Этот узел не найден!") {}
};
class Dublicate : public MyException
{
public:
    explicit Dublicate() : MyException("Такой узел уже есть!") {}
};

template<class T>
class List
{
    class Node
    {
    public:
        Node* next;
        T data;

        Node(T data)
        {
            this->data = data;
        }
    };

    class Iterator
    {
    private:
        Node* _node;
    public:
        friend class List;

        Iterator(Node* node) : _node(node) {}

        bool operator==(const Iterator& c) const
        {
            return _node == c._node;
        }

        bool operator!=(const Iterator& c) const
        {
            return !operator==(c);
        }

        T operator*() const
        {
            if (_node)
            {
                return _node->data;
            }

            return T();
        }

        void operator++()
        {
            if (_node)
            {
                _node = _node->next;
            }
        }
    };

    Node* pbeg;
public:
    List() { pbeg = NULL; }

    ~List()
    {
        if (pbeg != NULL)
        {
            Node* pb = pbeg;

            do
            {
                pb = pb->next;

                delete pbeg;

                pbeg = pb;
            } while (pb != pbeg);
        }
    }

    Iterator begin()
    {
        return Iterator(pbeg);
    }

    Iterator end()
    {
        return Iterator(pbeg);
    }

    Node* OneN(T d)
    {
        Node* pb = new Node(d);

        pbeg = pb;
        pbeg->next = pbeg;

        return pbeg;
    }

    Node* Push_front(T d)
    {
        Node* FindDub = pbeg;
        Node* NodeSim = FindForPush(d);

        do
        {
            if (FindDub == NodeSim)
            {
                throw Dublicate();
            }

            FindDub = FindDub->next;
        } while (FindDub != pbeg);

        Node* pb = new Node(d);

        Node* p = pbeg->next;

        pbeg->next = pb;
        pb->next = p;

        return pb;
    }

    bool Remove(T key)
    {
        if (Node* pkey = Find(key)) {
            if (pkey == pbeg)
            {
                pbeg = pbeg->next;
            }
            else
            {
                Node* rab = pbeg;

                do
                {
                    if ((rab->next) == pkey)
                    {
                        break;
                    }

                    rab = rab->next;
                } while (rab != pbeg);

                rab->next = pkey->next;
            }

            delete pkey;

            return true;
        }

        return false;
    }

    Node* FindForPush(T key)
    {
        Node* pb = pbeg;
        bool found = false;

        do
        {
            if ((pb->data) == key)
            {
                found = true;
                break;
            }

            pb = pb->next;
        } while (pb != pbeg);

        if (found)
        {
            return pb;
        }
    }

    Node* Find(T key)
    {
        Node* pb = pbeg;
        bool found = false;

        do
        {
            if ((pb->data) == key)
            {
                found = true;
                break;
            }

            pb = pb->next;
        } while (pb != pbeg);

        if (!found)
        {
            throw NotFound();
        }
        else
        {
            return pb;
        }
    }

    void Print()
    {
        cout << "Список: ";

        Iterator it = begin();
        do
        {
            cout << *it << ' ';

            ++it;
        } while (it != end());

        cout << endl;
    }
};