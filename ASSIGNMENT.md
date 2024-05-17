-V- English Translation below -V-

# מטלה 2 - גרפים והעמסת אופרטורים

במטלה הקודמת מימשתם את המחלקה `Graph.cpp` המאפשרת ייצוג של גרפים בעזרת מטריצת שכנויות. במטלה הזאת, אתם תרחיבו את המחלקה ותוסיפו תמיכה באופרטורים חשבוניים על גרפים.
כאמור, הגרפים מיוצגים בעזרת מטריצת שכנויות, לכן כל האופרטורים צריכים להיות חוקיים עבור מטריצות (כמו שלמדתם בקורס אלגברה לינארית).

אתם תצטרכו להוסיף את האופרטורים הבאים:

- שישה אופרטורים חשבוניים: חיבור (+) הוספה (+=) פלוס אונרי (+), ושלושת האופרטורים המקבילים לחיסור (-). כאמור, חיבור/חיסור של שתי מטריצות מוגדר רק על מטריצות מאותו סדר גודל nXn. ניסיון לחבר/לחסר שתי מטריצות שלא מקיימות תנאי זה יגרום לזריקת שגיאה.
- שישה אופרטורי השוואה: גדול, גדול-או-שווה, קטן, קטן-או-שווה, שווה, לא-שווה. לשם מטלה זו כללי השוואת גרפים הם כדלקמן:

  1. גרפים G1 ו-G2 ייקראו שווים אם הם מאותו סדר גודל ומכילים את אותן הצלעות (והמשקלים של הצלעות זהים) או אם G1 לא גדול מ-G2 וגם G2 לא גדול מ-G1.
  2. גרף G2 גדול מגרף G1 אם הגרף G1 מוכל ממש בגרף G2. אם אף גרף לא מוכל ממש בשני והגרפים לא שווים, אז גרף G2 גדול מגרף G1 אם מספר הצלעות ב-G2 גדול ממספר הצלעות ב-G1. אם בכל זאת מספר הצלעות זהה, אז הגרף G2 גדול מהגרף G1 אם המטריצה המייצגת של G2 בעלת סדר גודל גבוה יותר משל G1.

- הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי המספר. פעולה זו תגדיל או תקטין ב-1 את כל המשקלים של הצלעות בגרף.
- הכפלה בסקלר שלם (`int`) - מכפיל את המשקל של כל הצלעות.
- הכפלת גרפים - אנחנו מגדירים את פעולת הכפל בין גרף G1 לגרף G2 על ידי מכפלה של המטריצות המייצגות של שני הגרפים. התוצאה צריכה להיות מטריצה המייצגת גרף. ניסיון לבצע כפל בין גרפים בגדלים שונים צריך לזרוק שגיאה.
- אופרטור פלט - הדפסה הגיונית של הגרף (צורת ההפדסה היא לשיקולכם).


כמו כן, עליכם לכלול גם את הקובץ `Algorithms.cpp` מהמטלה הקודמת ולראות כיצד הפונקציות שהגדרתם בפעם הקודמת משתנות עכשיו. בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש).
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. אי עמידה בהנחיות תגרור הפחתה בציון.
בהצלחה!

ENGLISH:
# Assignment 2 - graphs and operator loading

In the previous assignment you implemented the class `Graph.cpp` which enables the representation of graphs with the help of an adjacency matrix. In this assignment, you will extend the class and add support for arithmetic operators on graphs.
As mentioned, the graphs are represented using an adjacency matrix, therefore all operators should be valid for matrices (as you learned in the linear algebra course).

You will need to add the following operators:

- Six arithmetic operators: addition (+) addition (+=) plus unary (+), and the three operators corresponding to subtraction (-). As mentioned, addition/subtraction of two matrices is defined only on matrices of the same size order nXn. Attempting to add/subtract two matrices that do not meet this condition will result in an error being thrown.
- Six comparison operators: greater, greater-or-equal, less, less-or-equal, equal, not-equal. For this task, the rules for comparing graphs are as follows:

   1. Graphs G1 and G2 will be called equal if they are of the same order of magnitude and contain the same edges (and the weights of the edges are the same) or if G1 is not greater than G2 and neither is G2 greater than G1.
   2. Graph G2 is larger than graph G1 if graph G1 is contained exactly in graph G2. If neither graph is exactly contained in the other and the graphs are not equal, then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1. If the number of edges is the same, then the graph G2 is larger than the graph G1 if the representative matrix of G2 has a higher order of magnitude than G1.

- Increase by 1 (++) and decrease by 1 (--) before and after the number. This action will increase or decrease by 1 all the weights of the edges in the graph.
- Multiplication by an integer scalar (`int`) - Multiplies the weight of all sides.
- Graph multiplication - we define the multiplication operation between graph G1 and graph G2 by multiplying the representative matrices of the two graphs. The result should be a matrix representing a graph. Attempting to perform multiplication between graphs of different sizes should throw an error.
- Output operator - logical printing of the graph (the form of the output is up to you).


Also, you should also include the `Algorithms.cpp` file from the previous assignment and see how the functions you defined last time change now. In addition to the files of the assignment, you are also required to submit a README file describing the method of implementation and the division you made in the code (a type of user guide).
You must write your ID number and email at the beginning of each file. Failure to comply with the guidelines will result in a grade reduction.
Successfully!