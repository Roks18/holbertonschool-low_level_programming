# Analyse de l'efficacité énergétique

## 1. Méthodologie de mesure

Les expériences ont été réalisées à l'aide de programmes écrits en langage C et compilés avec GCC en utilisant les options suivantes : `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`.

Le temps d'exécution a été mesuré avec la fonction `clock()` et la constante `CLOCKS_PER_SEC`. Ces outils permettent de calculer le temps processeur utilisé par un programme.

### Expérience Baseline

Le programme `baseline_loop.c` a effectué 100 millions d'itérations. Nous avons exécuté le programme trois fois afin d'observer les variations du temps d'exécution et de calculer une moyenne de référence.

Les résultats obtenus sont les suivants :

- Première exécution : 0,126282 seconde.
- Deuxième exécution : 0,124377 seconde.
- Troisième exécution : 0,122675 seconde.
- Temps moyen : environ 0,124445 seconde.

### Comparaison des algorithmes

Nous avons ensuite comparé deux algorithmes : une méthode naïve et une méthode appelée Single-pass. Chaque algorithme a été exécuté trois fois et son temps moyen a été calculé.

### Expérience d'instrumentation

Enfin, nous avons mesuré le temps d'exécution total d'un programme ainsi que celui de trois étapes individuelles :

- La création des données (*dataset construction*).
- Le traitement des données (*dataset processing*).
- Le calcul du checksum, une valeur utilisée pour vérifier le résultat du traitement.

## 2. Différences de performances observées

L'expérience Baseline a montré des temps d'exécution relativement proches. La différence entre la mesure la plus rapide et la plus lente était de 0,003607 seconde.

Cela montre que les trois mesures étaient assez stables, même si elles n'étaient pas exactement identiques.

La comparaison des algorithmes a montré une différence beaucoup plus importante.

Les temps moyens obtenus étaient :

- Algorithme naïf : 2,379959 secondes.
- Algorithme Single-pass : 0,000073 seconde.

D'après ces moyennes, l'algorithme naïf a pris environ 32 602 fois plus de temps que le Single-pass.

Cette différence peut s'expliquer par la structure des programmes. L'algorithme naïf utilise des boucles imbriquées, tandis que le Single-pass parcourt le tableau en un seul passage.

Cependant, les deux algorithmes n'ont pas produit le même résultat :

- Algorithme naïf : 625025000.
- Algorithme Single-pass : 25000.

Il faut donc rester prudent dans la comparaison. Les deux programmes ne semblent pas effectuer exactement le même calcul. Nous ne pouvons pas affirmer que le Single-pass est un remplacement plus rapide du programme naïf tout en conservant le même résultat.

L'expérience d'instrumentation a donné un temps total de 0,000414 seconde. Les trois étapes ont mesuré les durées suivantes :

- Création des données : 0,000182 seconde.
- Traitement des données : 0,000148 seconde.
- Calcul du checksum : 0,000082 seconde.

La création des données représente l'étape la plus longue parmi les trois étapes mesurées.

## 3. Relation entre le temps d'exécution et la consommation énergétique

Le temps d'exécution est un indicateur intéressant pour étudier l'efficacité d'un programme. Il permet de savoir combien de temps un programme utilise le processeur pour effectuer son travail.

Un programme qui termine son travail plus rapidement peut réduire la durée pendant laquelle le processeur est sollicité.

La comparaison des algorithmes montre une différence importante entre les temps d'exécution des deux méthodes.

Cependant, nos expériences n'ont pas mesuré directement la consommation électrique ni la puissance utilisée par le processeur. Nous ne pouvons donc pas calculer précisément l'énergie consommée ou les économies d'énergie réalisées.

Le temps d'exécution peut aider à étudier l'efficacité énergétique, mais il ne représente pas à lui seul une mesure de la consommation d'énergie.

## 4. Limites de l'expérience

Plusieurs limites doivent être prises en compte.

Premièrement, toutes les mesures ont été réalisées sur une seule machine. Les résultats peuvent varier selon le matériel, le système d'exploitation et les autres programmes en cours d'exécution.

Deuxièmement, l'expérience d'instrumentation a été réalisée une seule fois. Les durées mesurées étant très courtes, de petites variations peuvent influencer les résultats.

Troisièmement, les deux algorithmes comparés ne produisent pas le même résultat. Il n'est donc pas possible de considérer cette comparaison comme une preuve qu'un algorithme est plus rapide qu'un autre pour effectuer exactement le même travail.

Enfin, les expériences ont mesuré le temps processeur et non la consommation électrique réelle.

## 5. Conclusion et enseignements pratiques

Ces expériences montrent l'importance de mesurer les performances d'un programme avant de chercher à l'améliorer.

L'expérience Baseline permet d'obtenir un temps d'exécution de référence. La comparaison des algorithmes montre que la manière d'organiser les calculs peut avoir une grande influence sur les performances. L'instrumentation permet quant à elle d'identifier les étapes qui prennent le plus de temps.

Pour améliorer un programme, il est donc important de mesurer ses performances, de vérifier que les différentes versions produisent les mêmes résultats et de répéter les expériences dans des conditions aussi stables que possible.

Enfin, un programme efficace doit être rapide tout en produisant un résultat correct. Pour évaluer précisément son impact énergétique, il est nécessaire de réaliser des mesures directes de puissance ou de consommation électrique.
