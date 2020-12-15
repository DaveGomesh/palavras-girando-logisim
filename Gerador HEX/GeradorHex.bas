Attribute VB_Name = "GeradorHex"
Sub obterNumBinario()
    Dim numBin As String
    
'    Percorre o desenho
    For col = 5 To 12
        For lin = 8 To 15
            If Cells(lin, col).Value = 1 Then
                numBin = numBin & 1
            Else
                numBin = numBin & 0
            End If
        Next lin
        
'        Manda o valor Binario Obtido para conversao
        Cells(1, 2).Value = numBin
        Cells(17, col).Value = Cells(1, 1).Value
                
'        Reseta variaveis
        Cells(1, 2).Value = ""
        numBin = "0"
    Next col
End Sub

Sub limparMatriz()
'    Percorre toda a matriz limpando tudo
    For lin = 8 To 15
        For col = 5 To 12
            Cells(lin, col).Value = ""
        Next col
    Next lin
    
'    Limpa os valores Hexadecimais
    For col = 5 To 12
        Cells(17, col).Value = ""
    Next col
    
End Sub
