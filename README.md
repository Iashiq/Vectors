# Vectors
Vectors are a kind of sequence container. As such, their elements are ordered following a strict linear
sequence. Vector containers are implemented as dynamic arrays; just as regular arrays, vector
containers have their elements stored in contiguous storage locations, which means that their
elements can be accessed not only using iterators but also using offsets on regular pointers to
elements. But unlike regular arrays, storage in vectors is handled automatically, allowing it to be
expanded and contracted as needed.
Vectors are good at:
- Accessing individual elements by their position index (constant time).
- Iterating over the elements in any order (linear time).
- Add and remove elements from its end (constant amortized time).
Compared to arrays, they provide almost the same performance for these tasks, plus they have the
ability to be easily resized.
