# Library-Managements-System

School Library System is a lightweight CLI (Command Line Interface) application developed in C++. It is designed to help users manage a digital book collection by creating, viewing, and exporting data to a physical text file.

## Key Features
1. Add New Book: Quickly input book details including Title, Author, and Publication Year.
2. View Book List: Display all books currently stored in the system's temporary memory.
3. Delete Book: Remove specific entries from your current list before finalizing the data.
4. Save to File: Export your curated list into a book_list.txt file for external use.

## How to Use Effectively
To get the most out of this program, follow these steps:
1. Data Entry: Navigate to the "Add New Book" menu. Ensure all fields (Title, Author, and Year) are filled out accurately as requested by the program.
2. Verification: Periodically check the "View Book List" menu to confirm that your entries are correct and appearing as intended.
3. Curation: If you notice an error or wish to remove a book, use the "Delete Book" menu and enter the corresponding index number of the item you want to remove.
4. Finalize & Save: Once you are satisfied with your list, select "Save The Book". This will generate (or update) the book_list.txt file containing your complete collection.

## Important Notes & Limitations
1. As this is a simplified management system, please keep the following technical behaviors in mind to avoid accidental data loss:
2. Overwrite System: The program uses an "Overwrite" mode. Every time you select Save The Book, the existing book_list.txt file is completely replaced by the current session's data.
3. Volatile Memory: The program does not import data from the .txt file upon startup. If you close and restart the application, the internal list will reset to empty.
4. Manual Synchronization: Deleting a book within the program's menu does not modify the existing book_list.txt until you manually trigger the Save command again.
