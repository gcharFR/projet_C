# Design choices
- Hash values are stored and manipulated as strings in hexadecimal format as:
   - It is easier to display, read, compare...
   - As integers they span outside of the largest integers available to date
      (64 bits: unsigned long long)
- The lookup mode has been implemented using binary search trees

# Software architecture
- See diagram adjacent to this document representing the different modules and their internal dependencies
  (dependent module --> service-providing module). "precomputed_hash_table" is the main module.
     <img width="1024" height="662" alt="mermaid-1761507894982" src="https://github.com/user-attachments/assets/54f73d85-d961-4a56-ba0f-8ce524661688" />

