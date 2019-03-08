# Veränderungen in Excel

## (1) in __TN-Vorlage-2019.xlsm &rightarrow; !Teilnehmer
- L9 den Namen ``TN_FirstStepMonate`` gegeben
- N9 den Namen ``TN_Urlaub_errechnet`` gegeben
- Q10 &rightarrow; ``Tage Betriebsurlaub``
- P10 &rightarrow; ``=WENN(P7=0;0;SUMMENPRODUKT(('P:\Zeiterfassung\Zeiterfassung\[Teilnehmerliste_2019-mit-Makros.xlsm]Betriebsferien'!B:B>=TN_START)*('P:\Zeiterfassung\Zeiterfassung\[Teilnehmerliste_2019-mit-Makros.xlsm]Betriebsferien'!B:B<=TN_ENDE)))``
- P10 den Namen ``TN_Betriebsurlaub`` gegeben
- Q11 &rightarrow; ``Tage Indiv-Urlaub``
- P11 &rightarrow; ``=TN_Urlaub_errechnet-P10``
- P11 den Namen ``TN_Individualurlaub`` gegeben

## (2) in Makros &rightarrow; __TN-Vorlage-2019.xlsm &rightarrow; Module &rightarrow; utils
- in Zeile 71 Code eingefügt:
```
Public Function Range_FirstStepMonate() As Range
	Set Range_FirstStepMonate = TN_Sheet.Range("TN_FirstStepMonate")
End Function
```

## (3) in Makros &rightarrow; __TN-Vorlage-2019.xlsm &rightarrow; Module &rightarrow; Main &rightarrow; Stammdaten()
- Zeilen 114 bis 140 auskommentiert (manuelle Eingabe der Gesamturlaubstage)
- in Zeile 142 Code eingefügt:
```
    ' ================================
    ' ==== [TN First STep Monate] ====
    ' ================================
    
    ' First Step Monate
    Dim firstStepMonateTxt As String, _
        firstStepMonate As Long
        
    firstStepMonateTxt = InputBox( _
        Title:="Teilnehmer anlegen (IV): First Step", _
        Prompt:="Anzahl der Monate in First Step eingeben:", _
        Default:=Range_FirstStepMonate.Value)
        
    errMsg = "So wird das nichts!" + vbCr + vbCr _
        + "Die Anzahl der Monate muss eine Zahl (zwischen 0 und 3) sein!"
        
    If Not IsNumeric(firstStepMonateTxt) Then
        If firstStepMonateTxt <> "" Then MsgBox errMsg
        Exit Sub
    End If
        
    firstStepMonate = CLng(firstStepMonateTxt)
    
    If (firstStepMonate < 0 Or firstStepMonate > 3) Then
        MsgBox errMsg
        Exit Sub
    End If
```
- Zeile ``Range_Urlaub.Value = urlaubsTage`` auskommentiert
- Direkt darunter Code ``Range_FirstStepMonate.Value = firstStepMonate`` eingefügt

## (4) in __TN-Vorlage-2019.xlsm &rightarrow; !Kopiervorlage
- Tabelle ``Urlaub_aufgeteilt`` in K52 eingefügt (K-O:52-62)
- M55 &rightarrow; ``=WENNFEHLER(INDIREKT(TEXT($I$54;"MMMMJJJJ") & "!O55");TN_Individualurlaub)``
- M57 &rightarrow; ``=WENNFEHLER(INDIREKT(TEXT($I$54;"MMMMJJJJ") & "!O57");TN_Betriebsurlaub)``
- N55 &rightarrow; ``=V35``
- N57 &rightarrow; ``=V34``
- O55 &rightarrow; ``=M55-N55``
- O57 &rightarrow; ``=M57-N57``
- M61 &rightarrow; ``=SUMME(M55:M59)``
- N61 &rightarrow; ``=SUMME(N55:N60)``
- O61 &rightarrow; ``=SUMME(O55:O59)``


# Kommentare zu obigen Veränderungen

## (1) Betriebsurlaub automatisch berechnen
Dort wo die Tage und Monate der Zeit in der Maßnahme berechnet werden habe ich zwei Felder hinzugefügt (P10, P11), wo berechnet wird, wieviele Tage Betriebsurlaub während der Maßnahme vorkommen und wieviele individuelle Urlaubstage danach vom Gesamturlaub übrig bleiben. Zur Berechnung der Betriebsurlaubstage wird geschaut, wieviele der Tage in der Tabelle ``[Teilnehmerliste_2019-mit-Makros.xlsm]Betriebsferien`` zwischen Start- und Enddatum der Maßnahme liegen.

## (2) und (3) angepasste Eingabe der Teilnehmerdaten
Ich habe die Abfrage für die Eingabe der Teilnehmerdaten angepasst. Jetzt wird nicht mehr nach der Gesamtzahl der Urlaubstage gefragt, da diese automatisch berechnet werden können. Stattdessen wird jetzt abgefragt, wieviele Monate der Teilnehmer in First Step verbracht hat (0 wenn First Step gar nicht durchgeführt wurde).

## (4) neue Tabelle zu Urlaubstagen
In der Kopiervorlage für die Monats-Sheets kommt die Tabelle zur Aufteilung der Urlaubstage neu hinzu. Diese übernimmt für den ersten Monat der Maßnahme die Betriebs- und individuellen Urlaubstage vom Teilnehmer-Sheet (siehe (1)). Für alle darauf folgenden Monate wird immer Bezug auf den Vormonat genommen.

## Tests
- Wenn man einen neuen Teilnehmer anlegt und die Monatstabellen erstellt (über die zwei Knöpfe), dann kriegt man das erwünschte Ergebnis, und man wird aufgefordert, die Mappe wie gehabt abzuspeichern.
- Wenn man das Enddatum der Maßnahme bei einer bereits erstellten Mappe erhöht, werden für evtl. neu hinzu gekommene Monate automatisch Einträge in die Tabelle geschrieben und neue Monats-Sheets erstellt. Die Daten für die Anzahl der übrigen Urlaubstage werden auf allen Monats-Sheets automatisch angepasst.
