`epoll` est une abréviation pour "event poll" (sondage d'événements). C'est une interface fournie par le noyau Linux pour surveiller plusieurs descripteurs de fichiers afin de voir s'ils sont prêts pour des opérations d'E/S (lecture, écriture, etc.).

### Pourquoi `epoll` a été créé ?

`epoll` a été introduit pour résoudre les limitations de certaines interfaces précédentes utilisées pour la surveillance des descripteurs de fichiers, telles que `select` et `poll`. Voici un aperçu des méthodes précédentes et des problèmes qu'elles présentaient :

### Méthodes précédentes

1. **`select`** :

    - **Problèmes** :
        - **Limite de descripteurs de fichiers** : `select` a une limite fixe sur le nombre de descripteurs de fichiers qu'il peut surveiller, définie par la constante `FD_SETSIZE` (souvent 1024).
        - **Performance** : `select` doit vérifier chaque descripteur de fichier à chaque appel, ce qui peut être inefficace pour un grand nombre de descripteurs.
        - **Copie de données** : Les ensembles de descripteurs de fichiers doivent être copiés entre l'espace utilisateur et l'espace noyau à chaque appel, ce qui peut être coûteux en termes de performance.

2. **`poll`** :
    - **Problèmes** :
        - **Performance** : Bien que `poll` n'ait pas la limite fixe de descripteurs de fichiers de `select`, il doit toujours vérifier chaque descripteur de fichier à chaque appel, ce qui peut être inefficace pour un grand nombre de descripteurs.
        - **Copie de données** : Comme `select`, `poll` nécessite également la copie de structures de données entre l'espace utilisateur et l'espace noyau.

### Solutions apportées par `epoll`

`epoll` a été conçu pour surmonter ces limitations et offrir une meilleure performance et évolutivité. Voici quelques-unes des solutions qu'il apporte :

1. **Évolutivité** :

    - `epoll` peut gérer un nombre très élevé de descripteurs de fichiers sans les limitations de `select` et `poll`.

2. **Performance** :
    - **Notification basée sur les événements** : Contrairement à `select` et `poll`, `epoll` utilise un modèle basé sur les événements. Une fois qu'un descripteur de fichier est ajouté à l'instance `epoll`, le noyau surveille les événements et les signale uniquement lorsque des événements se produisent. Cela évite la nécessité de vérifier chaque descripteur de fichier à chaque appel.
    - **Pas de copie de données** : `epoll` utilise une interface de liste de descripteurs de fichiers, ce qui évite la copie répétée de structures de données entre l'espace utilisateur et l'espace noyau.
