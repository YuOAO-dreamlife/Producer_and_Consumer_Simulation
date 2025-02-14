在本專案中，有三種執行緒。
1. 「生產者」執行緒，每 0.01 秒隨機生產一個數字到暫存區(buffer)
2. 「消費者」執行緒，每 0.01 秒從暫存區中，消費最早產生的數字
3. 「顯示」執行緒，每 10 秒顯示一次暫存區的內容，以及消費者消費的順序。
這些執行緒會同時跑，直到程式結束為止。
例如生產者依序生產 1 2 3 4 5，消費者也依序消費 1 2 3 4 5
暫存區的大小為10，所有執行緒共用同一個暫存區。
如果暫存區滿了，生產者必須等消費者消費，不是滿的時候，才能繼續生產；
如果暫存區空了，消費者必須等生產者生產，不是空的時候，才能繼續消費。
此專案以下兩個程式：
1. produce_consume_homework.cpp：不考慮 Race condition
2. produce_consume_homework_mutex.cpp：考慮 Race condition，當有一個執行緒在存取暫存區時，鎖住其他執行緒。

This project includes three kinds of threads. 
1. The "producer" threads put one item with random value to the buffer.
2. The "consumer" threads get one oldest item in the buffer.
3. The "display" threads show the values in the buffer, and the order that the consumers get the items, per 10 seconds.
These threads run all the time until the program terminates.
For example, If the "producer" threads put 1 2 3 4 5 in order, then the "consumer" threads also get 1 2 3 4 5 in order.
We set the buffer size to 10, all the threads share one buffer.
If the buffer is full, the producer must wait until the buffer is not full.
If the buffer is empty, the consumer must wait until the buffer is not empty.
This project includes two programs as follows:
1. produce_consume_homework.cpp: Do not consider race condition
2. produce_consume_homework_mutex.cpp: Consider race condition, when one of the thread is accessing the buffer, lock other threads.
