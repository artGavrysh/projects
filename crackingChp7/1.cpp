/*
 *  Design the data structures for a generic deck of cards. 
 *  Explain how you would subclass it to implement particular card games.
 */
#include <stdio.h>
#include <iostream>

#define N_NUMBERS 13 
#define N_SUITES   4

enum Suit{
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Number{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card //singleton
{
private:
    Suit m_suit;
    Number m_number;
private:
    Card(Card const&) {} //don't implement
    Card operator=(Card const&) {} //don't implement 
public:
    Card(Number n, Suit s)
    {
        m_number = n;
        m_suit = s;
    }

    Suit getSuit(void)
    {
        return m_suit;
    }

    Number getNumber(void)
    {
        return m_number;
    }
};

class Deck
{
private:
    Card* m_store[N_SUITES * N_NUMBERS];
    int m_size;
public:
    Deck()
    {
        m_size = 0;
    }
    
    virtual ~Deck(){}

    int size(void)
    {
        return m_size;
    }

    void addCard(Card *c)
    {
        m_store[m_size++] = c;
    }

    Card* getCard(const Number n, const Suit s)
    {
        int i;
        Card *res;
        for (i = 0; i < m_size; i++)
        {

        if (s == m_store[i]->getSuit() && n == m_store[i]->getNumber())
        {
            res = m_store[i];
            while (i < m_size-1)
            {
                m_store[i] = m_store[i+1];
                i++;
            }
            m_size--;
            return res;
        }
        return NULL;
        }
    }
};

int main()
{
    Deck deck;
    
    Card *cardA = new Card(TWO, SPADES);
    Card *cardB = new Card(JACK, CLUBS);
    deck.addCard(cardA);
    deck.addCard(cardB);

    printf("Size of the deck: %d\n", deck.size());

    Card *cardC;
    Card *cardD;

    if ((cardC = deck.getCard(TWO, SPADES)) == NULL)
    {   
        printf("could not find \n");
        return -1;
    }

    printf("%d\n", cardC == cardA);

    cardD = deck.getCard(KING, DIAMONDS);
    
    printf("%d\n", cardD == cardB);
    
    return 0;
}
