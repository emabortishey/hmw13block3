Всё задание выполнено неплохо, однако возникла небольшая трудность, которая была устранена.
В проверке на правильность расстановки скобок планировалось следующее решение:
при чтении стека в случае встречи открывающейся скобки в конец стека с помощью пуша
записывалась такая же закрывающая, а при встрече закрывающей с помощью метода поп
последний символ извлекался (тобишь та самая добавленная скобка) и с помощью такого
алгоритма в случае правильной расстановки при встрече закрывающейся скобки было сравнение
с последним элементом (тобишь топ-1) в стеке, который должен был быть равен 
закрывающейся скобке, если их порядок был верным, однако этот метод потерпел крах ввиду того, что
в стеке используется не динамический массив и как я поняла из тестов программы, что-то не
сходилось конкретно из-за не динамической памяти массива стека. Я исправила это создав в 
методе проверки на корректность буферный массив (динамический в этот раз) и переменную
каунтер. Теперь при встрече открывающейся скобки в массив записывалась закрывающая и 
каунтер с помощью постфиксного (или префиксного, я в них путаюсь) ++ увеличивал его после
присваивания, и при встрече закрывающейся скобки теперь было сравнение уже с 
элементом буферного массива под индексом каунтер, который уменьшался если они были равны и
уже после замены методов поп и пуш в массив непосредственно стека на отдельно предназначенный
буферный массив программа заработала, именно из-за этого задание так затянулось на 5 дней,
ведь я не могла понять где именно была допущена ошибка, ведь алгоритм верен и память
выделена с большим запасом, но так и не поняв, решила изменить лишь бы быстрее закончить.
(+ я поняла в ходе, что стек может не содержать достаточно лишних ячеек для пуша скобочек
и это тоже была проблема, которая была решена добавлением буферного массива)

Принт_рес - бывший отдельный метод который был создан специально для вывода результата,
чтобы сам метод на проверку не взаимодействовал с консолью, вроде он есть в паре
коммитов, но после я его удалила, так как в методе по проверке расстановки также
создаётся строка, записывающая текущие символы из стека и при ошибке выводящая содержимое,
поэтому в конечном варианте возвращается стринг, либо равная "correct" либо
любая другая (равная строке до первой ошибки), чтобы также не происходило взаимодействия
с пользоваталем непосредственно в методе.