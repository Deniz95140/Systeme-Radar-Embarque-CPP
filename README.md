# 🛰️ Système de Radar Embarqué (C++ / POO)

## 📌 Présentation du Projet
Ce projet consiste en la conception et le développement d'un prototype de radar de recul pour systèmes embarqués. L'objectif est de mesurer la distance entre un capteur et un obstacle en temps réel, puis de traiter cette donnée pour fournir des alertes visuelles, sonores et textuelles à l'utilisateur.

Contrairement aux approches procédurales classiques, ce projet utilise une **architecture Orientée Objet (C++)**, garantissant une meilleure modularité et une maintenance simplifiée du code.

## 🚀 Fonctionnalités Clés
* **Mesure de précision** : Utilisation du capteur ultrasonique HC-SR04.
* **Interface LCD 16x2** : Affichage dynamique de la distance et des messages de statut.
* **Indicateurs d'état tricolores** : 
    * 🟢 **SECURE** (> 50cm) : Sécurité totale.
    * 🟡 **WARNING** (20cm - 50cm) : Approche détectée, alerte sonore intermittente.
    * 🔴 **DANGER** (< 20cm) : Proximité critique, alarme sonore continue.
* **Code Structuré** : Encapsulation de la logique matérielle dans des classes C++.

## 🛠️ Spécifications Matérielles (Simulées)
* **Microcontrôleur** : Arduino Uno R3.
* **Capteur** : HC-SR04 (Ultrasons).
* **Affichage** : Écran LCD 16x2.
* **Signaux** : 3 LEDs (Verte, Jaune, Rouge) + Piezo Buzzer.
* **Résistances** : 220Ω pour la protection des composants.

## 🧠 Logique de Fonctionnement
| Distance | Statut | LED | Alarme Sonore |
| :--- | :--- | :--- | :--- |
| > 50 cm | SECURE | Verte | Désactivée |
| 20 - 50 cm | WARNING | Jaune | Intermittente (500Hz) |
| < 20 cm | DANGER | Rouge | Continue (1200Hz) |

## 💻 Installation et Simulation
1. **Simulation interactive** : Le projet est disponible et testable sur Tinkercad via le lien suivant :  
   https://www.tinkercad.com/things/iMqW6xOeKnG-systeme-radar-embarque
2. **Déploiement physique** :
   * Cloner le dépôt,
   * Charger le fichier dans l'IDE Arduino.
   * Câbler les composants selon le schéma disponible dans le dossier `/assets`.
