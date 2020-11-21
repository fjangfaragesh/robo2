# Lösung der Vorbereitungs Aufgaben
## 1.
### static
- Eigenschaften sind nicht an Instanz, sondern an Klasse gebunden -> Existieren genau ein mal.
### public
- Eigenschaften überall Abrufbar
### protected
- Eigenschaften innerhalb Klasse und Vererbung Abrufbar
### priate
- Eigenschaften nur innerhalb Klasse Abrufbar
### function pointer
- Speichert pointer zu Funktion mit bestimmten parameter- und rückgabewert- Typen. Ist aber doof, weil raw Pointer und so.
### std::function<rückgabetyp(parametertyp1,parametertyp2,...)>
- Speichert pointer zu Funktion mit bestimmten parameter- und rückgabewert- Typen.
### unique Pointer
- Pointer zu Daten, es darf nur einen Pointer zu diesen geben. Wenn dieser weg, Daten werden gelöscht
### shared Pointer 
- Pointer zu Daten mit Referenzenzähler (anzahl der Pointer zu Daten). Wenn Zähler == 0, Daten werden gelöscht
### weak Pointer
- Wie shared Pointer, nur dass Referenzenzähler bei diesem nicht erhöht wird. Muss in shared Pointer um auf Daten zu zu greifen.