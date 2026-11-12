
# Task 07 – Diagnose, Redesign and Validate

## Objective:

To identify a performance limitation in an existing C++ program, redesign its data structure using suitable C++ concepts and validate the improvement through testing and performance measurements.

## Selected Program:

Task04 – Savings Account Mini-Statement

## A. Diagnosis of Limitation:

The original Savings Account implementation can use a fixed-size array with shifting to maintain the latest 10 transactions.

When the array becomes full, every new transaction requires shifting the remaining elements one position to the left to discard the oldest transaction.

This requires O(n) time for each insertion after the array reaches capacity.

## B. Measurable Objective:

Redesign transaction storage to reduce the number of element movements when adding new transactions.

The objective is to:
- Maintain the latest 10 transactions.
- Preserve the correct transaction order.
- Avoid shifting existing elements.
- Reduce insertion complexity from O(n) to O(1).

The experiment processes 100,000 transactions using both designs.

## C. Proposed Redesign:

The original shifting array is redesigned using a manually implemented circular buffer.

The circular buffer maintains:
- A fixed-size array.
- A count of stored transactions.
- A starting index that identifies the oldest transaction.

When the buffer is full, the oldest position is overwritten and the starting index is advanced using modulo arithmetic.

### Pseudocode:

1. Initialize the circular buffer.
2. If the buffer is not full:
   - Calculate the next available position.
   - Insert the transaction.
   - Increase the count.
3. Otherwise:
   - Overwrite the oldest transaction.
   - Advance the starting index.
4. Display transactions in chronological order.

### Design Comparison:

Original Design:
New transaction → Shift elements → Insert at the last position.

Redesigned Approach:
New transaction → Overwrite oldest position → Update circular index.

### Memory and Trade-off:

Both approaches use a fixed-size array of 10 transaction entries.

The circular buffer requires a starting index and uses modulo arithmetic. It avoids the repeated element movements of the shifting approach.

## D. Predicted Improvement:

Before implementation, the expected results are:

- Original shifting approach: O(n) insertion after the buffer is full.
- Circular buffer approach: O(1) insertion.
- Original element movements: 899,910 for 100,000 transactions.
- Circular buffer element movements: 0.
- Both approaches should display the same latest 10 transactions.

## E. Implementation and Validation:

The program implements both approaches using separate C++ classes.

Both designs receive the same 100,000 transaction values.

Validation checks:
- Both designs store the same number of transactions.
- Both display the same latest 10 transactions.
- The original approach performs 899,910 element movements.
- The circular buffer performs no shifting movements.
- Execution times are measured using the chrono library.

### Actual Performance Results:

Record the values obtained from your computer:

| Measurement | Shifting Array | Circular Buffer |
|---|---|---|
| Transactions | 100000 | 100000 |
| Element movements | 899910 | 0 |
| Execution time | Record actual result | Record actual result |
| Insertion complexity | O(n) | O(1) |

## F. Result and Justification:

The redesigned circular buffer produces the same latest 10 transactions as the original shifting array.

It eliminates repeated shifting and reduces insertion time complexity from O(n) to O(1).

Both implementations use the same fixed storage capacity. The redesigned approach requires maintaining a circular starting index, which adds a small amount of implementation complexity.

The original shifting approach may still be preferable for very small collections where simplicity is more important than insertion performance.

## Program:

Q7_DesignRedesignValidation.cpp

## Compiler:

GCC 16.2.0

## Compilation:

g++ -std=c++17 -Wall -Wextra Q7_DesignRedesignValidation.cpp -o q7

## Execution:

.\q7.exe

## Complexity Analysis:

Original shifting array:
- Insertion after full capacity: O(n)
- Display: O(n)
- Storage: O(n)

Redesigned circular buffer:
- Insertion: O(1)
- Display: O(n)
- Storage: O(n)

## Conclusion:

The experiment successfully identifies the shifting limitation and implements a circular buffer as an improved design. Validation confirms that both approaches preserve the same latest transactions while the redesigned approach eliminates repeated element movements.
