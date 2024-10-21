# Instruções do Software

Este programa resolve **EXCLUSIVAMENTE** o caso de carga estrela isolada (com o Nó N' não aterrado).

## Formato dos Valores de Entrada

- Todos os valores devem ser preenchidos em **notação cartesiana** (A + jB). 
- As tensões de fase dos geradores precisam ser convertidas para essa notação:
  - Parte real: V * cos(fase)
  - Parte imaginária: V * sin(fase)
  
**Exemplo:** Para inserir um valor de impedância `Z = 45`, basta escrever `45` e pressionar `Enter`.

## Como Inserir os Dados

Os dados de impedância e tensão devem ser preenchidos da seguinte forma:

- **Impedância (Z):** Z = (Zreal, Zim)
- **Tensão:** T = (Treal, Tim)
  
Para cada valor, pressione `Enter` após a inserção.

**Exemplo:** Para inserir a impedância `Z = 90 + j45`, `j50`, `j40.7`, use:
(90,45) (0,50) (0,40.7)


> **Importante:** Utilize **ponto** para separar decimais. Caso contrário, o programa encerrará inesperadamente.

## Exibição dos Resultados

Após inserir todos os dados corretamente, o programa exibirá:

- Matrizes de impedância de carga
- Matrizes de impedância de linha
- Módulo das tensões inseridas

Certifique-se de que os dados foram inseridos corretamente na **notação cartesiana**. Além disso, o programa fornecerá as correntes calculadas.

## Nota sobre Tensões de Fase em Cargas em Triângulo

Se for necessário calcular as tensões de fase em cargas configuradas em triângulo, é obrigatório **transformar manualmente as impedâncias de carga de Delta para Estrela** antes de inserir os valores no programa. Este software apenas calcula as correntes de linha para o circuito específico.

## Relembrando

- **As correntes são entregues em notação cartesiana!**
- **Use outro programa para converter os resultados para coordenadas polares, se necessário.**
