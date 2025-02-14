在本專案中，有三種執行緒。

1. 「生產者」執行緒，每 0.01 秒隨機生產一個數字到暫存區(buffer)。

2. 「消費者」執行緒，每 0.01 秒從暫存區中，消費最早產生的數字。

3. 「顯示」執行緒，每 10 秒顯示一次暫存區的內容，以及消費者消費的順序。

這些執行緒會同時跑，直到程式結束為止。

例如生產者依序生產 1 2 3 4 5，消費者也依序消費 1 2 3 4 5。

暫存區的大小為10，所有執行緒共用同一個暫存區。

如果暫存區滿了，生產者必須等消費者消費，不是滿的時候，才能繼續生產。

如果暫存區空了，消費者必須等生產者生產，不是空的時候，才能繼續消費。

此專案包含以下兩個程式：

1. produce_consume_homework.cpp：不考慮 Race condition。
![有Race Condition](https://github.com/user-attachments/assets/e8338bd2-038f-48eb-b0b7-88edabf8860e)

2. produce_consume_homework_mutex.cpp：考慮 Race condition，當有一個執行緒在存取暫存區時，鎖住其他執行緒。
![用mutex方式避免Race Condition](https://github.com/user-attachments/assets/9e93eca9-5494-4c34-9c47-67892d531f3f)
