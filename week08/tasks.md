### Задача 1
Реализирайте клас Student, който има като член данни: име, факултетен номер и специалност. Да се реализира клас StudentArray,
който да реализира функционалността на вектор. Да се реализират методи: 
- pushBack(...)
- pushFront(...)
- getBack();
- getFront(); 
- size();
- at(...);
Използвайте изключения и тяхното прихващане, само там където е нужно, за да подобрите използваемостта на вашия клас.


### Задача 2
Да се направи имплементация на класа String MyString Този клас трябва да съдържа следните методи:
- at(index) - Връща елемент от низа на опеределен index 
- front() - Връща първия елемент на низа
- back() - Връща последния елемент на низа
- str() - Връща самия низ, който се съдържа в String 
- length() - Връща дължината на низа 
- capacity() - Връща количеството заделена памет за низа
- empty() - Връща дали стринга е празен 
- append(<подходящ/и параметър/и>) - Долепя нов символ, низ или друг стринг
- clear() - Изчиства съдържанието на обекта, без да променя капацитета
- equals(<подходящ/и параметър/и) - Проверява дали два низа са равни 
- find(symbol) - Намира първото срещане на символ и връща индекса. Ако не намери, то да върне -1.
Използвайте изключения и тяхното прихващане, само там където е нужно, за да подобрите използваемостта на вашия клас.


Използвайте изключения и тяхното прихващане, само там където е нужно, за да подобрите използваемостта на вашия клас.
### Задача 3
Реализирайте клас Vector от числа със следните функционалности:

- pushBack(...)
- pushFront(...)
- getBack();
- getFront(); 
- size();
- at(...);
- popBack();
- clear();
- isEmpty();

### Задача 4
Ще създадем система за обработка на поръчки. Идеята е добре позната - клиент поръчва нещо за вкъщи. 
Създайте клас който описва ресторант. Всеки ресторант има име, което може да направите като статичен масив с най- много 25 символа.
Също така има и списък с произволна дължина (която се подава в конструктора) от продукти. 
Всеки продукт е низ с произволна дължина.
Поддържаме добавяне на продукт. Поддържаме и метод за получаване на поръчка. Създайте клас, който описва поръчка.
Всяка поръчка има име на ресторанта за когото е, брой продукти и списък с продуктите.
Ако в поръчката има продукт, който ресторанта не предлага, 
той хвърля грешка. В противен случай връща времето за доставка(време в минути, вие избирате каква точно да е логиката). 

Създайте клас Foodpandа, който има списък с ресторанти(отново с произволна дължина, която се задава в конструктора) и който прочита поръчки от конзолата.
Класът намира за кой ресторант е поръчката, ако има такъв, в противен случай изписва, че поръчката е невалидна понеже такъв ресторант не съществува.
Ако ресторантът съществува му я изпраща. Ако той хвърли грешка Foodpanda я хваща и съобщава, че даденият ресторант не предлага някой продукт от тези в поръчката. 
За всеки клас реализирайте нужните конструктори.
