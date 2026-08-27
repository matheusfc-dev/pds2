# Forbidden Words

A C++ program that censors a list of forbidden words found inside a message, replacing each occurrence with asterisks and reporting how many times each word was censored.

## 📋 Description

The program reads a set of "forbidden" words and a message. It then scans the message word by word: any word that exactly matches one of the forbidden words is replaced with a sequence of asterisks (`*`) of the same length. Finally, it prints the censored message followed by a summary showing how many times each forbidden word was replaced.

## 📥 Input

```
<number of forbidden words>
<forbidden word 1> <forbidden word 2> ... <forbidden word N>
<message>
```

- The first line contains an integer with the number of forbidden words.
- The second line contains that many forbidden words, separated by spaces.
- The third line contains the message to be censored (a full line, may contain multiple words).

## 📤 Output

1. The censored message, with each forbidden word replaced by asterisks of matching length.
2. One line per forbidden word, in the order given, reporting how many times it was found and replaced:

```
Palavra <word> substituida <count> vez(es).
```

## 💡 Example

**Input:**
```
2
bad awful
this is a bad and awful example
```

**Output:**
```
this is a *** and ****** example
Palavra bad substituida 1 vez(es).
Palavra awful substituida 1 vez(es).
```

## 🧠 Key concepts practiced

- Reading mixed input (integers, words, and a full line) with `cin` and `getline`
- Tokenizing a string into words using `stringstream`
- Working with `vector<string>` and fixed-size arrays
- String comparison and in-place replacement
- Counting occurrences with an auxiliary counter array

## 🛠️ How to compile and run

```bash
g++ -std=c++17 -Wall -o forbidden_words Proibidos.cpp
./forbidden_words
```

## 📁 Files

| File | Description |
|---|---|
| `Proibidos.cpp` | Main and only source file containing the full logic |
