--     UFRN: CIENCIA DA COMPUTA�AO: LPCP: GRUPO 6: 2010.1
--     Carlos Eduardo Maia
--     Fernando Chaves
--     Iuri Pereira
--     Victor Pereira


analisadorLexico :: String -> [String]
analisadorLexico "" = []
analisadorLexico arquivo = words(arquivo)

cabeca :: [String] -> String
cabeca [] = ""
cabeca (h:t) = h

cauda :: [String] -> [String]
cauda [] = []
cauda (h:t) = t

program_id :: [String] -> (Bool, [String])
program_id [] = (False, [])
program_id (h:l) = (True, l)

--DETECTA SE A STRING PASSADA � UM TIPO V�LIDO DA LINGUAGEM
tipoInvalido :: String -> Bool
tipoInvalido lex = if lex /= "void" && lex /= "int" && lex /= "bool" then True
      else False 

	  
--DEFINE O TIPO TABELAS E FUN�OES PARA EXTRAIR CABE�A E CAUDA
type TabelaS = [ElemTabelaS]

cabecaT :: TabelaS -> ElemTabelaS
cabecaT	(h:t) = h

caudaT :: TabelaS -> TabelaS
caudaT (h:t) = t  
	  
--DEFINE O TIPO ELEMTABELAS E OPERACOES PARA EXTRAIR SEU NOME, VALOR, TIPO E ESCOPO	  
type ElemTabelaS = (String, String, String, String)
nome :: ElemTabelaS -> String
valor :: ElemTabelaS -> String
tipo :: ElemTabelaS -> String
escopo :: ElemTabelaS -> String
nome (n,v,t,e) = n
valor (n,v,t,e) = v
tipo (n,v,t,e) = t
escopo (n,v,t,e) = e
  
--FUNCOES QUE ATUALIZAM NOME, VALOR E ESCOPO DE VARI�VEIS NA CABE�A TABELA DE S�MBOLOS  
atualizaNome :: (ElemTabelaS, String) -> ElemTabelaS
atualizaNome ((n,v,t,e), nNome) = (nNome, v, t, e) 

  
atualizaValor :: (ElemTabelaS, String) -> ElemTabelaS
atualizaValor ((n,v,t,e), nValor) = (n, nValor, t, e) 
  
atualizaEscopo :: (ElemTabelaS, String) -> ElemTabelaS
atualizaEscopo ((n,v,t,e), nEscopo) = (n, v, t, nEscopo) 



	  
-- ANALISA O ESPA�O DE DECLARA�AO DE VARI�VEIS E CRIA A TABELA DE S�MBOLOS
analisaDecl :: [String] -> (Bool, [String])
--analisaDecl lex = (True, lex)
analisaDecl lex =  
     if cabeca lex /= "}" then 
	 --chama a fun�ao que continua a analise caso o espa�o de declara�ao tenha sido conclu�do
	 if tipoInvalido (cabeca lex) then analisaInstrucoes (lex)
       else let aux = cauda lex in
         let locallex = aux in
         if cabeca locallex == ";" then (False, lex)
         else
           let aux = cauda locallex in
           let locallex = aux in
           if cabeca locallex /= ";" then (False, lex)
           else 
		    --inser��o dos elementos na tabela de s�mbolos no bloco de declara��o de vari�veis
			let tabelaSimbolos = (cabeca(cauda lex),"teste",cabeca lex, "teste"):tabelaSimbolos in
--		    do
--			 putStrLn(cabeca (cauda (cauda lex)))
			 analisaDecl (cauda (cauda (cauda lex)))
     else (True, lex)
--	 else (False, lex)
	 
	 
	 
analisaInstrucoes :: [String] -> (Bool, [String])       
analisaInstrucoes lex = (True, lex)

programa :: (Bool, [String])
programa = let lexema = analisadorLexico "void main ( ) { int a ; int b ; int c ; b = 2 ; c = 3 ; a = b + c ; }" in
 
   --ANALISA O INICIO DO PROGRAMA
   let backupLexema = lexema in
    if tipoInvalido (cabeca lexema) then (False, lexema)
    else let aux = cauda lexema in
      let lexema = aux in
    if cabeca lexema /= "main" then (False, lexema)
    else let aux = cauda lexema in
      let lexema = aux in
    if cabeca lexema /= "(" then (False, lexema)
    else let aux = cauda lexema in
      let lexema = aux in
    if cabeca lexema /= ")" then (False, lexema)
    else let aux = cauda lexema in
      let lexema = aux in
    if cabeca lexema /= "{" then (False, lexema)
    else let aux = cauda lexema in
      let lexema = aux in
    if cabeca lexema /= "}" then
	--chamada da fun�ao que analisa o espa�o de declara�ao e cria�ao da tabela de s�mbolos
	let tabelaSimbolos = [] in
	analisaDecl (lexema)
    else (True, lexema)