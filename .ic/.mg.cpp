//MillionGazillion
#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// implement a trie and use it to efficiently store string


class TrieNode
{
private:

    unordered_map<char, TrieNode*> nodeChildren_;

public:
    TrieNode() :
        nodeChildren_()
    {}

    ~TrieNode()
    {
        for (auto& v : nodeChildren_) {
            delete v.second;
        }
    }

    // copy and move constructors and assignment operators not shown

    bool hasChildNode(char ch) const
    {
        return nodeChildren_.find(ch) != nodeChildren_.cend();
    }

    void makeChildNode(char ch)
    {
        nodeChildren_.insert(make_pair(ch, new TrieNode()));
    }

    TrieNode * getChildNode(char ch)
    {
        auto it = nodeChildren_.find(ch);
        if (it == nodeChildren_.cend()) {
            return nullptr;
        }
        else {
            return it->second;
        }
    }
};

class Trie
{
private:
    TrieNode* rootNode_;
    static constexpr char END_OF_WORD_MARKER = '\0';

public:
    Trie() :
        rootNode_(new TrieNode())
    {
    }

    ~Trie()
    {
        delete rootNode_;
    }

    // copy and move constructors and assignment operators not shown

    bool addWord(const string& word)
    {
        TrieNode* currentNode = rootNode_;
        bool isNewWord = false;

        // Work downwards through the trie, adding nodes
        // as needed, and keeping track of whether we add
        // any nodes.
        for (const char ch : word) {
            if (!currentNode->hasChildNode(ch)) {
                isNewWord = true;
                currentNode->makeChildNode(ch);
            }
            currentNode = currentNode->getChildNode(ch);
        }

        // Explicitly mark the end of a word.
        // Otherwise, we might say a word is
        // present if it is a prefix of a different,
        // longer word that was added earlier.
        if (!currentNode->hasChildNode(END_OF_WORD_MARKER)) {
            isNewWord = true;
            currentNode->makeChildNode(END_OF_WORD_MARKER);
        }

        return isNewWord;
    }
};


















// tests

const lest::test tests[] = {
    {CASE("trie test") {
        Trie trie;
        EXPECT(trie.addWord("catch") == true);
        EXPECT(trie.addWord("cakes") == true);
        EXPECT(trie.addWord("cake") == true);
        EXPECT(trie.addWord("cake") == false);
        EXPECT(trie.addWord("caked") == true);
        EXPECT(trie.addWord("catch") == false);
        EXPECT(trie.addWord("") == true);
        EXPECT(trie.addWord("") == false);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}