### Задача 1
Да се на пише клас Vehicle, представляващ превозно средство. Обектите от този клас съдържат информация за:

- цвят;
- марка;
- година на производство;
- брой места/брой пътници, които може да превози;
- максимална скорост, която превозното средство може да развие.
Да се реализират конструктор по подразбиране, копиращ конструктор, оператор= и деструктор за класа.
По желание да се реализират и други конструктори, както е желателно да се добавят и гетъри и сетъри за полетата.

Да се реализира клас Bicycle, представляващ велосипед. Този клас наследява Vehicle.
Освен това, той има и полета с информация за:

- брой скорости;
- дали има светлини и/или светлоотразители;
- дали има звънче.
  
Да се реализират конструктор по подразбиране, копиращ конструктор, оператор= и деструктор за класа, ако са нужни.
По желание да се реализират и други конструктори, както е желателно да се добавят и гетъри и сетъри за собствените полета на класа.

Да се реализира клас Car, наследяващ Vehicle. Този клас съдържа още:

- модел;
- брой врати;
- мощност на двигателя в конски сили.
- Да се реализират конструктор по подразбиране, копиращ конструктор, оператор = и деструктор за класа.
- По желание да се реализират и други конструктори, както е желателно да се добавят и гетъри и сетъри за собствените полета на класа.

### Задача 2
Да се реализират: 

● абстрактен базов клас Device, описващ техническo устройствo, който съдържа производител (низ с произволна дължина)
и поддържа две операции: 

● print: за извеждане на информация за устройство; ○ get_perf: за намиране на числова мярка за производителност на устройството;

● производен клас Laptop, описващ лаптоп, който има допълнителна член-данна за скорост (цяло число мегахерци).

Да се дефинират двете операции print и get_perf, като: 

● информацията за лаптопа се състои от неговия производител и скорост;

● мярката за производителност на лаптопа е неговата скорост;

● производен клас Car, описващ автомобил, който има допълнителни член-данни за мощност (цяло число киловати) и обем на двигателя (цяло число cm3).

Да се дефинират двете операции print и get_perf, като:

● информацията за автомобила се състои от неговия производител, мощност и обем; 

● мярката за производителност на автомобила е неговата мощност;

● клас Inventory, описващ фирмен инвентар от устройства, които могат да бъдат лаптопи и коли. 

Да се реализират:

● функция, която извежда информация за всички устройства в списъка;

● функция, която проверява дали инвентарът е подреден в нарастващ ред по производителност.

### Задача 3
Да се реализира абстрактен базов клас Question, който описва следните операции върху въпрос от тест:

● ask, която извежда въпроса и въвежда негов отговор; 

● grade, която оценява въпрос и връща броя точки.

Да се реализират следните видове въпроси: 

● YesNoQuestion, който описва въпрос с два възможни отговора: да или не. При конструиране се задават текст, точки и верен отговор.
Въпросът дава 0 т. при грешен и пълен брой точки при верен отговор.

● MultipleChoice, който описва въпрос с няколко възможни отговори, от които някои са верни. При конструиране се задават текст, точки x, възможни и верни отговори.
Всеки правилно посочен отговор добавя x точки, а всеки погрешно посочен отговор отнема x точки.

● OpenQuestion, който описва въпрос със свободен текст. При конструиране се задават текст и брой точки.
При оценяване се извеждат въпроса и отговора и се въвежда оценка в проценти. Ако отговор не е даден, въпросът автоматично се оценява с 0 т.

Да се реализира клас Test, представящ тест с въпроси от всякакъв вид.

Да се реализират функциите:

● addQuestion, която добавя нов въпрос към теста;

● doTest, която задава всички въпроси подред и събира отговорите им;

● gradeTest, която оценява теста и връща броя събрани точки.
