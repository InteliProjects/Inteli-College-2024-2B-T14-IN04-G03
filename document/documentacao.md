

## RedLock

### Exodia

#### Bruno Fabiani, Gustavo Gonçalves, João Guilherme, Mateus Pretti, Murilo Couto, Rafael Furtado, Renan Reis

## Sumário
[1. Introdução](#c1)
  - [1.1 Objetivos](#c1-1)
    - [1.1.1 Objetivos gerais](#c1-1-1)
    - [1.1.2 Objetivos específicos](#c1-1-2)
  - [1.2 Proposta da solução](#c1-2)
  - [1.3 Justificativa](#c1-3)

[2. Metodologia](#c2)

[3. Desenvolvimento e Resultados](#c3)
  - [3.1 Domínio de Fundamentos de Negócio](#c3-1)
    - [3.1.1 Contexto da Indústria](#c3-1-1)
    - [3.1.2 Análise SWOT](#c3-1-2)
    - [3.1.3 Descrição da Solução a ser Desenvolvida](#c3-1-3)
      - [3.1.3.1 Qual é o problema a ser resolvido](#c3-1-3-1)
      - [3.1.3.2 Qual a solução proposta (visão de negócios)](#c3-1-3-2)
      - [3.1.3.3 Como a solução proposta deverá ser utilizada](#c3-1-3-3)
      - [3.1.3.4 Quais os benefícios trazidos pela solução proposta](#c3-1-3-4)
      - [3.1.3.5 Critério de sucesso e avaliação](#c3-1-3-5)
    - [3.1.4 Value Proposition Canvas](#c3-1-4)
    - [3.1.5 Matriz de Riscos](#c3-1-5)
    - [3.1.6 Política de Privacidade de acordo com a LGPD](#c3-1-6)
      - [3.1.6.1 Informações gerais sobre a empresa](#c3-1-6-1)
      - [3.1.6.2 Informações sobre o tratamento de dados](#c3-1-6-2)
      - [3.1.6.3 Quais são os dados coletados](#c3-1-6-3)
      - [3.1.6.4 Onde os dados são coletados](#c3-1-6-4)
      - [3.1.6.5 Finalidades dos dados](#c3-1-6-5)
      - [3.1.6.6 Armazenamento dos dados](#c3-1-6-6)
      - [3.1.6.7 Período de retenção dos dados](#c3-1-6-7)
      - [3.1.6.8 Uso de cookies e tecnologias semelhantes](#c3-1-6-8)
      - [3.1.6.9 Compartilhamento de dados](#c3-1-6-9)
      - [3.1.6.10 Medidas de segurança](#c3-1-6-10)
      - [3.1.6.11 Direitos dos usuários](#c3-1-6-11)
      - [3.1.6.12 Exercício de direitos](#c3-1-6-12)
      - [3.1.6.13 Informações de contato do DPO](#c3-1-6-13)
    - [3.1.7 Bill of Material (BOM)](#c3-1-7)
  - [3.2 Domínio de Fundamentos de Experiência de Usuário](#c3-2)
    - [3.2.1 Personas](#c3-2-1)
    - [3.2.2 Jornada do Usuário](#c3-2-2)
    - [3.2.3 Storyboards](#c3-2-3)
  - [3.3 Solução Técnica](#c3-3)
    - [3.3.1 Requisitos Funcionais](#c3-3-1)
    - [3.3.2 Requisitos Não Funcionais](#c3-3-2)
    - [3.3.3 Arquitetura da Solução](#c3-3-3)
      - [3.3.3.1 Banco de dados](#c3-3-3-1)
    - [3.3.4 Arquitetura do Protótipo](#c3-3-4)
    - [3.3.5 Arquitetura Refinada da Solução](#c3-3-5)
  - [3.4 Resultados](#c3-4)
    - [3.4.1 Protótipo Inicial do Projeto](#c3-4-1)
    - [3.4.2 Protótipo Físico do Projeto (offline)](#c3-4-2)
    - [3.4.3 Protótipo do Projeto com MQTT e I2C](#c3-4-3)
    - [3.4.4 Protótipo Físico do Projeto (online)](#c3-4-4)
    - [3.4.5 Protótipo Final do Projeto](#c3-4-5)
    - [3.4.6 Testes de Usabilidade](#c3-4-6)
      - [3.4.6.1 Contexto dos Testes](#c3-4-6-1)  
      - [3.4.6.2 Problemas Detectados e Resultados Obtidos](#c3-4-6-2)  
      - [3.4.6.3 Próximos Passos e Planejamento de Correção](#c3-4-6-3)  

[4. Conclusões e Recomendações](#c4)

[5. Referências](#c5)

<br>

# <a name="c1"></a>1. Introdução

&nbsp;&nbsp;&nbsp;&nbsp;O Instituto Apontar consiste em uma organização sem fins lucrativos, originária da fusão entre a Associação de Assistência ao Adolescente (AAA) e o Instituto Lecca, somando 74 anos de história e atuação em prol do acesso à educação à criança e ao adolescente com altas habilidades. O Instituto Apontar atua em diversas localidades próximas à capital do Rio de Janeiro.

&nbsp;&nbsp;&nbsp;&nbsp;O Instituto Apontar possui dois programas de capacitação de jovens, sendo eles, o Programa Arcos, responsável por identificar alunos com altas habilidades e oferece atividades de suplementação pedagógica e acompanhamento psicossocial, visando incluir os alunos em escolas de excelência, proporcionando suporte aos alunos até o fim da educação básica. Por outro lado, o Programa A+, que atende alunos do 6° ao 9° ano das escolas municipais do Rio de Janeiro, oferece atividades complementares de todas as matérias da grade curricular, além do seu pilar de desenvolvimento cultural, viabilizando diversas atividades culturais, como visitas a museus, teatros, entre outros.

&nbsp;&nbsp;&nbsp;&nbsp;Atualmente, há algumas dificuldades operacionais no sistema de controle de acesso às imediações do Instituto, o que complica o registro de frequência. Para resolver essa questão, é necessário aprimorar o sistema de controle de acesso com uma solução tecnológica que disponibilize uma base de dados completa com esses registros. Logo, o projeto RedLock do grupo Exodia, busca sanar esse problema de uma maneira fácil e intuitiva.

## 1.1 Objetivos <a id="c1-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O principal objetivo do Instituto Apontar é aprimorar as formas de acesso ao espaço do instituto, pretendendo atender às necessidades específicas de controle de acesso e frequência, facilitando o processo de marcar presença dos alunos e ponto dos funcionários, além de controlar melhor o fluxo de visitantes.

### 1.1.1 Objetivos gerais <a id="c1-1-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O Instituto Apontar busca aprimorar os processos de controle de acesso e frequência para garantir mais eficiência em suas operações. Para isso, pretende automatizar o monitoramento de presença de alunos e funcionários, reduzindo a necessidade de registros manuais, evitando erros e acelerando o processo. Além disso, visa melhorar o controle de quem acessa suas dependências, permitindo identificar em tempo real todos os presentes, inclusive visitantes. Outro objetivo fundamental é disponibilizar os dados coletados em um banco de dados integrado a planilhas excel, facilitando o acesso às informações capturadas pelos sensores e dispositivos IoT.

### 1.1.2 Objetivos específicos <a id="c1-1-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Para atingir esses objetivos gerais, é essencial implementar dispositivos IoT conectados à internet, que automatizem os processos de registro de presença e acesso. A criação de um banco de dados estruturado garantirá o armazenamento adequado das informações coletadas por essa tecnologia. Por fim, a solução visa oferecer um acesso prático ao Instituto, evitando erros humanos e simplificando o processo de controle de entrada e saída.


## 1.2 Proposta da solução <a id="c1-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nossa proposta de solução é a implementação de um sistema de controle de acesso e monitoramento de presença, utilizando dispositivos IoT e sensores biométricos para automatizar o registro de entrada e saída de alunos e colaboradores do Instituto Apontar.

&nbsp;&nbsp;&nbsp;&nbsp;Esse sistema resolverá o problema da necessidade de registros manuais propensos a erros, oferecendo uma alternativa automatizada e eficiente. Além disso, o monitoramento em tempo real permitirá uma melhor gestão da presença e frequência, atuando no controle de acesso ao Instituto, inclusive para visitantes. Todos os dados capturados pelos sensores serão armazenados em um banco de dados centralizado e disponibilizados em tabelas, facilitando o acesso à informação e análise por parte dos gestores.

&nbsp;&nbsp;&nbsp;&nbsp;Dessa forma, nossa solução atende aos objetivos de melhorar a segurança, reduzir erros manuais, aumentar a eficiência dos registros de presença e acesso, além de disponibilizar dados de maneira prática, tornando os processos de controle de acesso menos complicados e mais intuitivos e segura, onde os dados estão protegidos contra acessos não autorizados, para a tomada de decisões consciente.

## 1.3 Justificativa <a id="c1-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp;A implementação do sistema de controle de acesso baseado em IoT e biometria oferece um diferencial significativo ao integrar tecnologias para automatizar processos que tradicionalmente são manuais e propensos a erros. O uso de sensores biométricos garante um alto nível de segurança enquanto a conectividade via IoT permite o monitoramento em tempo real, algo que os sistemas convencionais de controle de acesso ainda não oferecem de forma eficiente.

**Benefícios esperados com a nossa solução:**  
- **Maior precisão e agilidade no controle de presença**: A eliminação de registros manuais reduz a chance de erros e acelera o processo de verificação.  
- **Monitoramento em tempo real**: Com a integração IoT, os gestores terão acesso imediato às informações de quem está presente no Instituto, permitindo uma resposta rápida em situações emergenciais, por exemplo.  
- **Segurança aprimorada**: O uso de biometria impede acessos não autorizados, garantindo que apenas pessoas cadastradas tenham permissão para entrar nas instalações, melhorando o controle sobre funcionários, alunos e visitantes.  
- **Disponibilidade de dados**: A centralização dos dados em um banco de dados acessível e sua disponibilização em planilhas facilita a análise de padrões e o acompanhamento da frequência e presença, proporcionando dados estratégicos para a gestão.

&nbsp;&nbsp;&nbsp;&nbsp;Contudo, nossa solução não apenas atende às necessidades operacionais do Instituto Apontar, mas também introduz uma infraestrutura tecnológica moderna que melhora significativamente a segurança e a eficiência do controle de acesso. Além disso, proporciona uma experiência mais fluida para alunos e funcionários, destacando-se pela sua praticidade e pela facilidade de integrar informações à gestão do Instituto. Esse sistema posiciona o Instituto como uma instituição inovadora alinhada às tendências tecnológicas atuais, com foco em segurança e eficiência, o que fortalece a reputação da organização perante seus alunos, colaboradores e doadores.

# <a name="c2"></a>2. Metodologia

&nbsp;&nbsp;&nbsp;&nbsp;A metodologia utilizada nesse projeto é baseada no **RM-ODP** (*Reference Model of Open Distributed Processing*), um padrão internacional definido pela ISO/IEC e pela ITU. Ele é amplamente utilizado na especificação de arquiteturas de sistemas distribuídos heterogêneos e abertos, fundamentado nos conceitos de orientação a objetos. Sua estrutura é organizada em cinco pontos de vista consistentes entre si, que capturam todos os requisitos para o desenvolvimento do sistema, abrangendo desde as necessidades dos processos de negócios até os requisitos de tecnologia. Além disso, o RM-ODP inclui conceitos gerais para elaboração dos pontos de vista, um modelo que suporta a transparência de distribuição e princípios para avaliação de conformidade de sistemas ODP.

&nbsp;&nbsp;&nbsp;&nbsp;Abaixo colocamos um gráfico que ilustra os pontos de vista da RM-ODP, que servirão como base para a arquitetura deste projeto.

<div align="center">
<sub>Figura 1 - Pontos de Vista da RM-ODP</sub>  
<img src="..\document/assets/business/RM-ODP.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Os pontos de vista do RM-ODP são detalhados da seguinte maneira:

- **Ponto de Vista Computacional:** Concentra-se na definição das funções desempenhadas pelos comportamentos do sistema e de suas interações. Ele oferece uma visão clara de como os elementos colaboram para atingir seus objetivos, sendo importante para a modelagem funcional e alocação de responsabilidades.

- **Ponto de Vista de Empresa:** Relacionado aos objetivos organizacionais, aborda as políticas, metas e regras de negócios do sistema. Ele garante que o sistema esteja alinhado às prioridades do projeto.

- **Ponto de Vista de Informação:** Engloba a modelagem dos dados do sistema e o comportamento esperado em diferentes situações, garantindo a consistência e precisão no tratamento das informações e a integridade do fluxo de dados entre os componentes.

- **Ponto de Vista de Engenharia:** Focado nos aspectos técnicos, define a infraestrutura necessária para suportar as interações, lidando com desafios de desempenho, escalabilidade e confiabilidade em sistemas complexos.

- **Ponto de Vista de Tecnologia:** Especifica os detalhes técnicos do projeto, como ferramentas, frameworks e plataformas utilizadas, garantindo que as tecnologias sejam compatíveis e adequadas ao escopo da solução.

&nbsp;&nbsp;&nbsp;&nbsp;Essa metodologia é amplamente reconhecida por sua flexibilidade e por permitir a análise aprofundada de sistemas distribuídos, independentemente do seu tamanho ou complexidade. Sua abordagem estruturada é particularmente útil para projetos que demandam alto grau de organização e alinhamento entre as equipes.

&nbsp;&nbsp;&nbsp;&nbsp;Abaixo colocamos uma imagem que ilustra os pontos de vista adaptados da RM-ODP, ajustados para facilitar a aplicação prática neste projeto.

<div align="center">
<sub>Figura 2 - Pontos de Vista da RM-ODP adaptado ao projeto</sub>  
<img src="..\document\assets\business\RM-ODP-ADAPTADO.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;As adaptações realizadas foram feitas para simplificar e agilizar o processo de desenvolvimento:

- **Visão de Tecnologia:** Permanece inalterada.  
- **Visão de Negócio:** Anteriormente chamada de "Empresa", foi renomeada para "Negócios", refletindo uma nomenclatura mais comum no ambiente corporativo e facilitando a compreensão pelos stakeholders.  
- **Visão de Engenharia:** Renomeada para "Arquitetura", pois o termo é mais frequentemente associado ao planejamento estrutural de sistemas, tornando a visão mais intuitiva para o contexto do projeto.  
- **Visões de Informação e Computacional:** Reformuladas como "Requisitos Funcionais" e "Requisitos Não Funcionais". Ambas abordagens simplificam os tópicos e os alinham diretamente às práticas comuns de análise e desenvolvimento.

&nbsp;&nbsp;&nbsp;&nbsp;Essa adaptação foi concebida para trazer praticidade e agilidade ao processo de desenvolvimento, mantendo os conceitos-chave do RM-ODP, mas ajustando-os para atender às demandas específicas do nosso projeto. Essa abordagem permite maior eficiência e alinhamento durante o desenvolvimento, garantindo uma entrega de qualidade e com menor risco de falhas.

# <a name="c3"></a>3. Desenvolvimento e Resultados 

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, abordaremos o desenvolvimento do projeto e os resultados esperados, detalhando o processo desde a concepção até a execução da solução proposta. Serão apresentados os fundamentos que sustentam a abordagem do projeto, análises estratégicas e as soluções implementadas para atender às necessidades específicas do Instituto Apontar. Com isso, buscamos demonstrar como o sistema de controle de acesso automatizado contribuirá para melhorar a gestão, segurança e eficiência operacional da instituição.

## 3.1. Domínio de Fundamentos de Negócio <a id="c3-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;A seguir, exploramos os fundamentos de negócio que embasam o desenvolvimento deste projeto. Serão abordados o contexto da indústria educacional, as principais características do Instituto Apontar, suas necessidades específicas e os desafios enfrentados. Além disso, utilizaremos ferramentas estratégicas, como as 5 Forças de Porter e a Análise SWOT, para entender melhor o cenário competitivo e identificar oportunidades e ameaças. Essa base analítica é fundamental para justificar a necessidade da solução proposta e garantir que ela esteja alinhada aos objetivos e à missão do Instituto Apontar.

### 3.1.1. Contexto da Indústria <a id="c3-1-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O Instituto Apontar, inicialmente era a ONG Associação de Assistência aos Adolescente (AAA), fundada em 1950, na cidade do Rio de Janeiro, que posteriomente se transformou no Instituto Apontar, sempre com um objetivo inicial de oferecer assistência social a jovens de menor renda. Após longos anos de trabalho voluntário, o instituto atualmente trabalha com crianças e adolescentes com traços de altas habilidades e superdotação de baixa renda para garantir seus direitos básicos de educação, sociais e culturais. A ONG atua em um setor de crescente importância e transformação: a educação, com foco em integrações tecnológicas e inovações no ambiente escolar. Essa área educacional está passando por uma crescente evolução, impulsionada pela demanda por métodos de ensino mais tecnológicos e eficientes. Assim, o Instituto Apontar se destaca ao implementar soluções que facilitam o acompanhamento e gestão dos alunos, trazendo transparência para o cotidiano.

&nbsp;&nbsp;&nbsp;&nbsp;Mesmo tendo um excelente posicionamento no mercado educacional, o Instituto Apontar possui alguns concorrentes que também oferecem suporte a alunos de altas habilidades e baixa renda. Um desses competidores é a ONG Gerando Falcões, que atua no Brasil inteiro, oferecendo programas educacionais para jovens prodígios das comunidades de todo o país. Outro concorrente é o Instituto Rogério Steinberg, uma entidade sem fins lucrativos que atua desde 1998, atendendo crianças e jovens socialmente vulneráveis com Altas Habilidades/Superdotação (AH SD). O IRS executa atividades suplementares de educação, com foco no desenvolvimento de talentos que muitas vezes passam despercebidos. Além desse, existe também a organização MENSA Brasil, uma organização sem fins lucrativos que faz parte da rede internacional MENSA, desenvolvida para reunir e apoiar pessoas com alto QI. No Brasil, a MENSA atua identificando e promovendo o desenvolvimento de pessoas de todas as idades com altas habilidades e superdotação, oferecendo oportunidades para que seus possam expandir suas capacidades intelectuais e encontrar um espaço livre para troca de conhecimentos. Por fim, é importante ressaltar que nenhuma dessas organizações visam competir. Mas todas compartilham o mesmo compromisso de ajudar crianças e jovens a desenvolverem seus potenciais e contribuir para o seu crescimento pessoal e social. 

&nbsp;&nbsp;&nbsp;&nbsp;O modelo de negócio do Instituto Apontar é baseado em oferecer apoio especializado a alunos com altas habilidades e superdotação, por meio de programas educacionais que visam desenvolver suas competências acadêmicas e socioemocionais. Como ONG, o instituto depende de doações, parcerias com outras instituições e apoio governamental para financiar suas atividades. Por meio de uma abordagem colaborativa, eles trabalham diretamente com a comunidade local do Rio de Janeiro, promovendo o impacto social e garantindo oportunidades para que esses alunos possam atingir seu potencial máximo.

&nbsp;&nbsp;&nbsp;&nbsp;O desenvolvimento de novas tendências no âmbito de apoio aos alunos indica um crescimento no uso de tecnologias avançadas e personalização do ensino. Instituições estão se beneficiando da IoT, inteligência artificial e análise de dados para criar ambientes de aprendizagem mais dinâmicos, além de monitorar o desenvolvimento dos alunos de modo prático. Com isso, há uma crescente valorização do desenvolvimento socioemocional, com programas que integram habilidades como empatia, resiliência e trabalho em equipe, indo além do ensino acadêmico tradicional. Outra tendência é a expansão de parcerias entre ONGs e setores públicos e privados, possibilitando mais recursos e maior alcance dos programas.

&nbsp;&nbsp;&nbsp;&nbsp;Nesse contexto, o Instituto Apontar demonstra possuir algumas dificuldades, como a falta de controle do acesso dos alunos no prédio. Essa situação gera desafios na gestão do fluxo e na garantia da segurança, especialmente em horários de pico, quando o movimento é mais intenso e as atividades extracurriculares estão em andamento. A ausência de um sistema integrado de monitoramento dificulta o acompanhamento em tempo real dos horários de entrada e saída dos alunos, resultando em informações limitadas para os responsáveis.

&nbsp;&nbsp;&nbsp;&nbsp;Para compreender melhor o ambiente em que o Instituto Apontar está inserido e os desafios que enfrenta, é essencial realizar uma análise estratégica que permita identificar os fatores internos e externos que impactam sua operação. Uma ferramenta para essa avaliação é o modelo das **5 Forças de Porter**, que introduz sobre a competitividade do setor e as dinâmicas que influenciam o sucesso do Instituto. 

<br>  

&nbsp;&nbsp;&nbsp;&nbsp;As 5 Forças de Porter são um framework de análise setorial que permite entender o nível de competitividade de um mercado. O modelo apresenta os atores envolvidos (concorrentes, fornecedores, compradores, novos entrantes e substitutos), como eles se relacionam e como influenciam o sucesso dos negócios.

<div align="center">
<sub>Figura 3 - 5 Forças de Porter</sub>
<img src="..\document\assets\business\5forcasDePorter.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

#### Ameaça de novos entrantes
&nbsp;&nbsp;&nbsp;&nbsp;A ameaça de novos entrantes no setor de ONGs voltadas à educação de crianças com altas capacidades cognitivas é relativamente moderada. Embora a criação de ONGs seja mais acessível, diversos fatores dificultam a entrada de novos entrantes. Primeiramente, atender alunos superdotados exige uma equipe extremamente especializada, com ampla experiência em campos específicos. Outro fator é a necessidade de uma boa reputação no setor. O Instituto Apontar tem mais de 70 anos de atuação, construindo uma reputação sólida, sendo algo que dificulta a entrada de novos entrantes.

&nbsp;&nbsp;&nbsp;&nbsp;Além disso, os recursos necessários para uma estrutura adequada são fatores que impactam no aparecimento de novos entrantes. O Instituto Apontar tem uma base de doadores e parceiros bem estabelecidos, o que fortalece a sua presença no setor. Para ONGs que desejem apresentar os mesmos serviços é extremamente desafiador, especialmente em um setor onde diversas ONGs disputam os mesmos doadores. Portanto, enquanto o setor de ONGs pode parecer acessível em um primeiro momento, a combinação de expertise técnica necessária, credibilidade e financiamento faz com que a ameaça de novos entrantes seja contida, beneficiando instituições já consolidadas como o Instituto Apontar.

#### Poder de barganha dos fornecedores
&nbsp;&nbsp;&nbsp;&nbsp;O poder de barganha dos fornecedores é relativamente baixo. Nesse caso, os fornecedores podem ser plataformas de tecnologia educacional e materiais didáticos. Em um cenário onde a tecnologia educacional está cada vez mais acessível, o instituto pode escolher entre diversos fornecedores. Por exemplo, empresas de tecnologia como a Google for Education, Microsoft e plataformas de aprendizado virtual como a Coursera possibilitam uma ampla gama de conteúdos educativos gratuitos ou de baixo custo. Esses serviços não apenas reduzem o poder de barganha dos fornecedores, mas também permitem que o instituto se adapte rapidamente a novas tecnologias sem um alto custo de mudança. 

#### Poder de barganha dos clientes
&nbsp;&nbsp;&nbsp;&nbsp;Em um cenário onde o Instituto Apontar atua como uma ONG sem fins lucrativos, o poder de barganha dos clientes é baixo. Os jovens atendidos pela instituição não pagam pelos serviços fornecidos pelo instituto, e, isso reduz a pressão exercida pelos clientes e permite que o Instituto foque na missão educacional, sem enfrentar demandas de clientes pagantes.

#### Ameaça de produtos substitutos
&nbsp;&nbsp;&nbsp;&nbsp;A ameaça de produtos substitutos no setor educacional voltado a crianças superdotadas é moderada, mas não pode ser ignorada. Uma dessas alternativas seriam escolas particulares que oferecem programas especializados para alunos superdotados, sendo uma alternativa para famílias que têm condições de pagar por esse tipo de educação. Além disso, com a evolução das tecnologias educacionais, existem plataformas que usam inteligência artificial para personalizar a abordagem para cada aluno. Essa plataformas de aprendizado digital, como a Khan Academy e o Google Classroom, que adaptam o conteúdo com base no desempenho do usuário, embora não substituam completamente o atendimento especializado oferecido pelo instituto, representam uma opção complementar para famílias que procuram reforço no desenvolvimento cognitivo de seus filhos.

#### Rivalidade entre os Concorrentes
&nbsp;&nbsp;&nbsp;&nbsp;Embora existam outras ONGs com o mesmo objetivo, a rivalidade nesse setor é baixa, pois elas buscam ajudar as crianças e jovens superdotados, sem a necessidade de “roubar” clientes entre si. No entanto, a competição por financiamento é real, especialmente em tempos de crise econômica, quando as doações e subsídios diminuem. Por exemplo, outras ONGs voltadas à educação e desenvolvimento cognitivo podem competir pelo apoio financeiro de grandes fundações e empresas que priorizam causas educacionais.

### 3.1.2. Análise SWOT <a id="c3-1-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp; A análise SWOT é uma ferramenta estratégica muito utilizada para examinar fatores internos e externos que afetam uma organização ou projeto. O termo "SWOT" corresponde a Strengths (Forças), Weaknesses (Fraquezas), Opportunities (Oportunidades) e Threats (Ameaças). Forças e fraquezas referem-se a elementos internos, como recursos e competências da empresa, enquanto oportunidades e ameaças estão relacionadas a fatores externos, como mudanças no mercado. Essa metodologia ajuda as organizações a identificar áreas de melhoria, explorar novas possibilidades e minimizar riscos, servindo como um guia para a tomada de decisões mais informadas. Abaixo, você encontra um quadro ilustrativo com os principais pontos da análise SWOT do Instituto Apontar:

<div align="center">
<sub>Figura 4 - Matriz SWOT </sub>
<img src="..\document\assets\business\matrizSWOT.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

### Forças (Strengths)

- **Foco em um público subatendido:**  
  O Instituto, ao focar em um público minoritário, crianças e adolescentes superdotados que foram negligenciados pelo sistema educacional, preenche uma lacuna fundamental na sociedade que impacta diretamente na sua falta de concorrência direta.

- **Alto impacto educacional:**  
  Com resultados expressivos, como 73% dos alunos aprovados no vestibular em 2023 participarem do “top 10”, o Instituto Apontar demonstra impacto social significativo na formação acadêmica do seu público-alvo.

- **Método de ensino personalizado:**  
  Atuações como complementação e suplementação pedagógica e assistência psicossocial formam um método de ensino personalizado e um acompanhamento adjacente, o que se revela como uma das grandes forças do Instituto.

- **Rede sólida de apoio e parcerias:**  
  O Instituto tem uma rede de investidores e parceiros estratégicos estáveis, que fornecem recursos importantes para a execução dos projetos e expansão do seu impacto.

- **Capacitação contínua de alunos e ex-alunos:**  
  Ex-alunos se tornando professores dentro da instituição fortalecem um ciclo de aprendizagem e crescimento constante, “reabastecendo” profissionais capacitados e estabelecendo um processo duradouro.

### Fraquezas (Weaknesses)

- **Dependência financeira de doações:**  
  Como uma ONG, o Instituto Apontar depende de doações e investimentos, o que pode limitar ações significativas e estabilidade financeira em tempos de crise.

- **Infraestrutura tecnológica limitada:**  
  A falta de recursos financeiros ou análise de dados aprofundada demonstra fragilidade tecnológica e ausência de políticas alavancadoras como *Data-Driven*, que podem ajudar a aumentar seu impacto social.

- **Falta de abrangência nacional:**  
  Apesar do impacto significativo no Rio de Janeiro, o Instituto ainda não possui uma presença forte em outras regiões do Brasil, limitando o alcance do seu trabalho.

### Ameaças (Threats)

- **Concorrência por recursos:**  
  Como uma ONG que atinge um público muito específico, o Instituto Apontar não tem concorrentes diretos, todavia, ainda disputa investimentos e doações com outras ONGs e instituições educacionais que atuam em áreas similares.

- **Horário de funcionamento:**  
  Com a nova carga horária do ensino médio, que requer dos alunos presença integral, o Instituto possui grandes dificuldades no ajuste de sua hora de funcionamento para conseguir atender todos os seus alunos.

- **Mudanças nas políticas públicas de educação:**  
  Mudanças em leis ou políticas voltadas à educação pública e privada podem impactar o apoio a programas voltados para alunos com altas habilidades.

### Oportunidades (Opportunities)

- **Aumento da conscientização sobre superdotação:**  
  Com a crescente conscientização de diversos grupos sociais, adolescentes e crianças superdotadas podem ganhar mais reconhecimento. Assim, o Instituto Apontar pode expandir sua atuação para outras regiões e ganhar mais visibilidade.

- **Expansão de programas tecnológicos:**  
  Com uma maior aplicação da tecnologia nos processos internos e externos da ONG, a organização poderia automatizar processos desgastantes e ter maior controle de diferentes fluxos, aumentando a eficiência da instituição.

- **Captação de recursos via leis de incentivo:**  
  O uso de leis de incentivo fiscal, como o ISS e a Lei Rouanet, oferece uma oportunidade de captar recursos significativos, tanto de pessoas físicas quanto de empresas.

&nbsp;&nbsp;&nbsp;&nbsp; Em conclusão, o Instituto Apontar se destaca por seu foco em um público subatendido, oferecendo uma solução educacional única e de alto impacto para crianças e adolescentes superdotados, que são muitas vezes negligenciados pelo sistema educacional tradicional. Através de um método de ensino personalizado e um ciclo de capacitação contínua, o Instituto fortalece suas operações com uma sólida rede de apoio e parcerias estratégicas. No entanto, a dependência financeira de doações e a limitação de sua infraestrutura tecnológica são desafios significativos que podem restringir o crescimento e a sustentabilidade da organização.

&nbsp;&nbsp;&nbsp;&nbsp; Além disso, embora não enfrente concorrência direta devido ao seu público-alvo específico, o Instituto ainda precisa lidar com a disputa por recursos com outras ONGs e a necessidade de ajustar sua carga horária para atender às mudanças educacionais recentes. No entanto, o aumento da conscientização sobre superdotação e as oportunidades de captação de recursos via leis de incentivo fiscal representam caminhos promissores para expansão e fortalecimento. Com o aumento da eficiência tecnológica e maior reconhecimento em nível nacional, o Instituto Apontar tem o potencial de ampliar seu impacto e solidificar sua posição como referência no apoio a jovens com altas habilidades.

### 3.1.3. Descrição da Solução a ser Desenvolvida <a id="c3-1-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Para resolver os desafios identificados no controle de acesso e monitoramento de frequência no Instituto Apontar, é necessário implementar uma solução tecnológica automatizada. Esta seção apresenta em detalhes a solução desenvolvida, abordando o problema específico a ser resolvido, a visão de negócios da proposta, seu funcionamento, os benefícios esperados e os critérios para avaliar o sucesso da implementação. O objetivo é garantir maior precisão nos registros, otimização dos processos administrativos.

#### 3.1.3.1 Qual é o problema a ser resolvido <a id="c3-1-3-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O problema a ser resolvido é a ineficiência no controle de acesso e no monitoramento da frequência de alunos e colaboradores do Instituto, que atualmente é feito de forma manual. Esses procedimentos estão sujeitos a erros humanos, como falhas na anotação de horários ou no registro de entradas de alunos ou funcionários, dessa forma comprometendo a precisão dos dados e dificultando o acompanhamento da presença. Além disso, o controle manual não permite a geração automática de relatórios, o que aumenta o tempo e o esforço dos colaboradores para analisar essas informações, prejudicando a supervisão em tempo real.

#### 3.1.3.2 Qual a solução proposta (visão de negócios) <a id="c3-1-3-2"></a>
&nbsp;&nbsp;&nbsp;&nbsp;A solução proposta consiste na implementação de um sistema automatizado de controle de acesso e monitoramento de frequência, utilizando tecnologia de leitura biométrica para reconhecimento de quem acessou e integração com planilhas que exibem os dados. O sistema faz o registro de entradas e saídas de alunos e colaboradores de maneira automática, garantindo a geração de relatórios que evitem erros humanos, que poderão ser visualizados através de uma interface visual.
<br>
&nbsp;&nbsp;&nbsp;&nbsp;Além de otimizar o gerenciamento interno, a solução também aprimora a segurança, assegurando que apenas pessoas autorizadas tenham acesso ao Instituto. A integração com planilhas facilita o compartilhamento e a consulta de informações, aumentando a eficiência operacional e reduzindo o tempo gasto em processos manuais.

#### 3.1.3.3 Como a solução proposta deverá ser utilizada <a id="c3-1-3-3"></a>
&nbsp;&nbsp;&nbsp;&nbsp;A solução será utilizada para registrar automaticamente os horários de entrada e saída de alunos e colaboradores, integrando esses dados a uma planilha que facilite a consulta individual de frequência por meio de uma interface visual. Nessa interface, será possível visualizar gráficos de presença por aluno e por turma, além de obter informações como a média de tempo nos estabelecimentos e o registro de presença. O sistema também permitirá a criação automática de relatórios de presença e controle de horários.

#### 3.1.3.4 Quais os benefícios trazidos pela solução proposta <a id="c3-1-3-4"></a>
- Melhoria na segurança com o uso de biometria.
- Melhor visualização dos acessos através de uma interface.
- Automação na criação de relatórios de acesso.
- Redução de falhas e inconsistências associadas ao controle manual.
- Aumento da precisão e eficiência no controle de acesso e frequência.
- Integração com planilhas para colocar os registros.

#### 3.1.3.5 Qual será o critério de sucesso e qual medida será utilizada para o avaliar <a id="c3-1-3-5"></a>
&nbsp;&nbsp;&nbsp;&nbsp;O critério de sucesso será a implementação eficaz do sistema de controle de acesso, com a geração de relatórios precisos e automáticos, e o uso consistente da biometria para registrar entradas e saídas. As medidas utilizadas para avaliar o sucesso serão:
- A precisão dos dados de acesso e frequência registrados.
- Criação de relatórios dos acessos com boa visualização.
- A redução de falhas de resgistro.
- A consistência na atualização dos dados em tempo real.
- A satisfação dos gestores do Instituto com a facilidade de uso do sistema.

### 3.1.4. Value Proposition Canvas <a id="c3-1-4"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O Canvas de Proposta de Valor é uma ferramenta de negócios que permite que sejam destacados os diferenciais que a empresa terá dentro do mercado, mostrando as maneiras como o produto satisfaz as verdadeiras necessidades do cliente. É composto por dois blocos principais, sendo eles o perfil do cliente e o mapa de valor, cada um com três subcategorias:

Perfil do Cliente:

- **Tarefas do Cliente:**

  - _Garantir o controle de acesso de alunos e colaboradores às salas de aula_
  - _Criar planilhas a partir do acesso dos alunos e colaboradores para relatórios e acompanhamento_
  - _Monitorar frequência e horário de entrada e saída de alunos e colaboradores_

- **Dores:** 

  - _Controle manual e ineficiente de acesso, frequência e horário, oque era exaustivo e impreciso_
  - _Risco de entradas não serem registradas_
  - _Dificuldade na criação de relatórios e na analise de frequência e pouca visualização dos dados obtidos_
  
- **Ganhos:**

  - _Automação no controle de acesso e frequência, com aumento da eficiência na coleta de registros_
  - _Maior precisão nos dados de presença e horário_
  - _Facilidade em consultar e monitorar dados históricos de frequência_
  - _Com a visualização das planilhas poder analisar de forma gráfica as presenças e tempos e gerar relatórios de forma rápida e automática, integrados com planilhas_
  

Proposta de Valor:

- **Produtos e serviços:** 

  - _Sistema de controle de acesso a partir de biometria_
  - _Automação da atualização de logs em tempo real_
  - _Visualização de relatórios e gráficos, através de uma integração com as planilhas de acessos_

- **Aliviadores de dores:** 

  - _Sistema automatizado que tira o controle manual, reduzindo dessas formas erros causados pela imprecisão humana_ 
  - _Visualização simplificada dos relatórios, para dessa forma ter uma visualização mais limpa e também analisar gráficos das informações_ 
  - _Monitoramento de acessos atualizados em tempo real, para dessa forma ter mais controle dos acessos_ 

- **Criadores de ganho:** 

  - _Melhoria no gerenciamento e na segurança de dados_
  - _Melhora na visualização gráfica dos relatórios_
  - _Aumento da precisão nas informações de presença e pontualidade, beneficiando a organização como um todo_
  - _Automação na coleta de dados_

<br>

<div align="center">
<sub>Figura 5 - Canvas de Proposta de Valor </sub>
<img src="..\document\assets\business\propostadevalor.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;O Canvas de Proposta de Valor, é possível identificar como a solução proposta atende às necessidades específicas do Instituto Apontar, aliviando suas principais dores e criando ganhos significativos para a organização. Ao substituir processos manuais e ineficientes por um sistema automatizado de controle de acesso e monitoramento de frequência, a instituição pode garantir maior precisão nos registros, otimizar a geração de relatórios e melhorar a segurança operacional.

### 3.1.5. Matriz de Riscos	<a id="c3-1-5"></a>
&nbsp;&nbsp;&nbsp;&nbsp;Uma matriz de risco é uma ferramenta utilizada para avaliar e gerenciar os riscos em projetos, processos ou empreendimentos. Ela organiza os riscos em uma matriz, geralmente com eixos que representam a probabilidade de ocorrência e o impacto dos riscos. Isso permite priorizar ações para mitigar ou evitar os riscos mais significativos, ajudando a garantir o sucesso do projeto ou empreendimento. Além disso, é importante ressaltar que a matriz de risco é dinâmica e muda de acordo com o andamento do projeto, pois novos riscos podem surgir, enquanto outros podem se tornar menos relevantes. Portanto, é essencial revisá-la periodicamente para manter o controle eficaz dos riscos ao longo do tempo.

<div align="center">
<sub>Figura 6 - Matriz de Risco do Projeto</sub>
<img src="..\document\assets\business\matriz_de_risco_modulo4.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>
<div align="center">
<sub>Quadro 01 - Matriz de risco detalhada</sub>
</div>

| Ameaças                                         | Plano de Ação                                                                                            |
| ----------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| Código conter bugs que afetem seu desempenho                         | Implementar revisão de código frequente e testes automatizados                                                              |
| Incompatibilidade com sistemas existentes    | Realizar uma análise dos sistemas atuais do Instituto antes de iniciar a integração, garantindo que os requisitos de compatibilidade sejam claros e que as possíveis incompatibilidades sejam resolvidas antes do desenvolvimento
| Leitor biométrico falhar                      | Buscar ajuda dos orientadores para evitar o uso incorreto do leitor                            |
| Problemas no computador | Sempre realizar commits para evitar perdas |
| Queima de peças do Hardware | Criar estoque de peças de reposição e realizar manutenções regulares |
| Risco de quebra de conformidade com normas de privacidade de dados | Realizar auditorias regulares para garantir conformidade com a LGPD, revisar políticas internas e implementar criptografia para proteger dados sensíveis |
| Riscos de incompatibilidade com futuras atualizações tecnológicas | Desenvolver o sistema utilizando padrões abertos e tecnologias amplamente adotadas |
| Vulnerabilidade da Segurança | Implementar medidas de proteção, como firewalls e criptografia |

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Assim, quando se trata do desenvolvimento de um projeto, é de extrema importância a realização de uma matriz de risco, a fim de entender as possíveis oportunidades e ameaças que possam afetar no desenvolvimento do projeto.

### 3.1.6. Política de Privacidade de acordo com a LGPD <a id="c3-1-6"></a>

**Última atualização: Dezembro de 2024.**

&nbsp;&nbsp;&nbsp;&nbsp;A Política de Privacidade é um documento que descreve como uma empresa coleta, usa, compartilha e protege as informações pessoais dos usuários. Sendo importante para garantir transparência nas práticas de tratamento dos dados, auxiliando as pessoas a entenderem como suas informações serão utilizadas e quais direitos possuem em relação a esses dados. A Política abrange sobre assuntos como, quais tipos de dados são coletados, as finalidades dessa coleta, com quem essas informações podem ser compartilhados e as medidas de segurança adotadas para protegê-los.

<br>

**Instituto Apontar**

#### 3.1.6.1 Informações gerais sobre a empresa / organização <a id="c3-1-6-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O Instituto Apontar, pessoa jurídica de direito privado, com sede na Rua Morais e Vale, 111 - Centro, Rio de Janeiro - RJ, 20.021-260, inscrita no CNPJ/MF sob o nº 34.050.815/0001-05, zela pela segurança e proteção de dados de todos os seus clientes, parceiros, fornecedores e usuários do site [institutoapontar.org.br](https://institutoapontar.org.br/) e qualquer outro site e/ou aplicativo operado pela empresa.

&nbsp;&nbsp;&nbsp;&nbsp;O grupo Exodia, estudantes na faculdade Inteli (Instituto de Tecnologia e Liderança), em parceria com o Instituto Apontar, está comprometida com a proteção dos dados pessoais em conformidade com a Lei Geral de Proteção de Dados Pessoais (LGPD). Trabalhamos em conjunto com o Instituto Apontar para assegurar que todas as práticas de tratamento de dados, desde a coleta até o armazenamento, sigam rigorosamente as disposições legais aplicáveis. Nosso objetivo é garantir que as informações dos usuários sejam tratadas de forma transparente, segura e em conformidade com as exigências regulatórias, oferecendo total confiança aos nossos clientes e parceiros.

&nbsp;&nbsp;&nbsp;&nbsp;Esta Política de Privacidade destina-se a informá-lo sobre o modo como nós utilizamos e divulgamos informações coletadas em suas visitas à nossa empresa e em mensagens que trocamos com você.

&nbsp;&nbsp;&nbsp;&nbsp;Ter seus dados pessoais bem cuidados é um direito protegido pela Lei 13.709, conhecida como a Lei Geral de Proteção de Dados Pessoais (LGPD).

&nbsp;&nbsp;&nbsp;&nbsp;AO ACESSAR O CONTEÚDO, ENVIAR COMUNICAÇÕES OU FORNECER QUALQUER TIPO DE DADO PESSOAL, VOCÊ DECLARA ESTAR CIENTE E DE ACORDO COM ESTA POLÍTICA DE PRIVACIDADE, A QUAL DESCREVE AS FINALIDADES E FORMAS DE TRATAMENTO DE SEUS DADOS PESSOAIS QUE VOCÊ DISPONIBILIZAR À EMPRESA.

&nbsp;&nbsp;&nbsp;&nbsp;Esta Política de Privacidade fornece uma visão geral de nossas práticas de privacidade e das escolhas que você pode fazer, bem como direitos que você pode exercer em relação aos Dados Pessoais tratados por nós. Se você tiver alguma dúvida sobre o uso de Dados Pessoais, entre em contato com nosso DPO (Data Protection Officer) ao final do documento.

&nbsp;&nbsp;&nbsp;&nbsp;Além disso, a Política de Privacidade não se aplica a quaisquer aplicativos, produtos, serviços, site ou recursos de mídia social de terceiros que possam ser oferecidos ou acessados por meio da empresa. O acesso a esses links fará com que você deixe a empresa e possa resultar na coleta ou compartilhamento de informações sobre você por terceiros. Nós não controlamos, endossamos ou fazemos quaisquer representações sobre esses sites de terceiros ou suas práticas de privacidade, que podem ser diferentes das nossas. Recomendamos que você revise a política de privacidade de qualquer site com o qual você interaja antes de permitir a coleta e o uso de seus Dados Pessoais.

&nbsp;&nbsp;&nbsp;&nbsp;**Caso você nos envie Dados Pessoais referentes a outras pessoas físicas, você declara ter a competência para fazê-lo e declara ter obtido o consentimento necessário para autorizar o uso de tais informações nos termos desta Política de Privacidade.**

#### 3.1.6.2 Informações sobre o tratamento de dados <a id="c3-1-6-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Para os fins desta Política de Privacidade, foi descrito os seguintes termos:

- **“Dados Pessoais”**: significa qualquer informação que, direta ou indiretamente, identifique ou possa identificar uma pessoa natural, como por exemplo, nome, CPF, data de nascimento, endereço IP, dentre outros;
- **“Dados Pessoais Sensíveis”**: significa qualquer informação que revele, em relação a uma pessoa natural, origem racial ou étnica, convicção religiosa, opinião política, filiação a sindicato ou a organização de caráter religioso, filosófico ou político, dado referente à saúde ou à vida sexual, dado genético ou biométrico;
- **“Tratamento de Dados Pessoais”**: significa qualquer operação efetuada no âmbito dos Dados Pessoais, por meio de meios automáticos ou não, tal como a coleta, gravação, organização, estruturação, armazenamento, adaptação ou alteração, recuperação, consulta, utilização, divulgação por transmissão, disseminação ou, alternativamente, disponibilização, harmonização ou associação, restrição, eliminação ou destruição. Também é considerado Tratamento de Dados Pessoais qualquer outra operação prevista nos termos da legislação aplicável;
- **“Leis de Proteção de Dados”**: significa todas as disposições legais que regulem o Tratamento de Dados Pessoais, incluindo, porém sem se limitar, a Lei nº 13.709/18, Lei Geral de Proteção de Dados Pessoais (“LGPD”).

#### Controlador e Operador dos Dados

&nbsp;&nbsp;&nbsp;&nbsp;Nesta parceria, o Instituto Apontar atua como Controlador dos Dados, sendo responsável por definir as finalidades e os meios de tratamento dos Dados Pessoais. Isso significa que o Instituto Apontar é a entidade que decide quais dados serão coletados, como serão utilizados, e com quais terceiros esses dados poderão ser compartilhados, sempre de acordo com as diretrizes estabelecidas na Lei Geral de Proteção de Dados Pessoais (LGPD).

&nbsp;&nbsp;&nbsp;&nbsp;O grupo Exodia, por sua vez, atua como Operador dos Dados. Isso significa que a equipe realiza o tratamento dos Dados Pessoais em nome da empresa, seguindo rigorosamente as instruções fornecidas pelo Controlador. O Operador não possui autonomia para decidir sobre as finalidades e os meios de tratamento dos dados, devendo agir estritamente conforme o estabelecido pelo parceiro e em conformidade com as disposições legais.

#### 3.1.6.3 Quais são os dados coletados <a id="c3-1-6-3"></a>

No contato com a empresa, nós podemos coletar:

- **Dados pessoais**: Nome completo, número de telefone, endereço completo, endereço de e-mail, CPF e dados escolares. De quaisquer aluno e/ou responsável;
- **Informações que você envia**: Informações que você envia via formulário (dúvidas, reclamações, sugestões, críticas, elogios etc.).
- **Dados Biométricos**: Ao passar pelas catracas de acesso, será capturada uma imagem da pessoa para fins de identificação e controle de acesso. A coleta de fotos será realizada com o objetivo exclusivo de garantir a segurança nas dependências do Instituto e monitorar os horários de entrada e saída. Para viabilizar o acesso às instalações do Instituto, será realizado o cadastro da biometria do titular de dados.

#### 3.1.6.4 Onde os dados são coletados <a id="c3-1-6-4"></a>

Na navegação geral na empresa, nós poderemos coletar:

- **Dados de localização**: Dados de geolocalização quando você acessa a empresa;
- **Preferências**: Informações sobre suas preferências e interesses em relação aos produtos/serviços (quando você nos diz o que eles são ou quando os deduzimos do que sabemos sobre você);
- **Dados de navegação na empresa**: Informações sobre suas visitas e atividades na empresa, incluindo o conteúdo (e quaisquer anúncios) com os quais você visualiza e interage, informações sobre o navegador e o dispositivo que você está usando, seu endereço IP, sua localização, o endereço do site a partir do qual você chegou. Algumas dessas informações são coletadas usando nossas Ferramentas de Coleta Automática de Dados, que incluem cookies, web beacons e links da web incorporados. Para saber mais, leia como nós usamos Ferramentas de Coleta Automática de Dados no item abaixo;
- **Dados anônimos ou agregados**: Respostas anônimas para pesquisas ou informações anônimas e agregadas sobre como a empresa é usufruída. Durante nossas operações, em certos casos, aplicamos um processo de desidentificação ou pseudonimização aos seus dados para que seja razoavelmente improvável que você seja identificado através do uso desses dados com a tecnologia disponível;
- **Outras informações que podemos coletar**: Outras informações que não revelem especificamente a sua identidade ou que não são diretamente relacionadas a um indivíduo, tais como informações sobre navegador e dispositivo; dados de uso da empresa; e informações coletadas por meio de cookies, pixel tags e outras tecnologias.

&nbsp;&nbsp;&nbsp;&nbsp;A MENOS QUE VOCÊ INFORME EM ALGUM FORMULÁRIO LIVRE PREENCHIDO POR VOCÊ, NÓS NÃO COLETAMOS DADOS PESSOAIS SENSÍVEIS.

#### Não fornecimento de Dados Pessoais

&nbsp;&nbsp;&nbsp;&nbsp;Você não é obrigado a compartilhar os Dados Pessoais que solicitamos. No entanto, se você optar por não os compartilhar, em alguns casos, não poderemos fornecer a você acesso completo ao instituto, alguns recursos especializados ou ser capaz de prestar a assistência necessária ou, ainda, viabilizar a entrega do produto ou prestar o serviço contratado por você.

#### 3.1.6.5 Para quais finalidades os dados serão utilizadas <a id="c3-1-6-5"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Coletamos e usamos Dados Pessoais para gerenciar seu relacionamento conosco e melhor atendê-lo quando você estiver adquirindo produtos e/ou serviços na empresa, personalizando e melhorando sua experiência.

Exemplos de como usamos os dados incluem:

- Viabilizar que você adquira produtos e/ou serviços na empresa;
- Confirmar ou corrigir as informações que temos sobre você;
- Enviar informações que acreditamos ser do seu interesse;
- Personalizar sua experiência;
- Personalizar o envio de publicidades para você, baseada em seu interesse em nossa empresa;
- Entrar em contato por um número de telefone e/ou endereço de e-mail fornecido. Podemos entrar em contato com você através de equipamentos de discagem automática, por mensagens de texto (SMS), por e-mail, ou por qualquer outro meio de comunicação que seu dispositivo seja capaz de receber, nos termos da lei e para fins comerciais razoáveis.

Além disso, os Dados Pessoais fornecidos também podem ser utilizados na forma que julgarmos necessária ou adequada:
- Nos termos das Leis de Proteção de Dados;
- Para atender exigências de processo judicial;
- Para cumprir decisão judicial, decisão regulatória ou decisão de autoridades competentes, incluindo autoridades fora do país de residência;
- Para proteger nossas operações;
- Para proteger direitos, privacidade, segurança nossos, seus e/ou de terceiros;
- Para detectar e prevenir fraude;
- Permitir-nos usar as ações disponíveis ou limitar danos que venhamos a sofrer;
- De outros modos permitidos por lei.

#### 3.1.6.6 Onde os dados ficam armazenados <a id="c3-1-6-6"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Seus dados são armazenados pelo controlador, os quais são geridos de acordo com as melhores práticas de segurança da informação. As melhores práticas de segurança da informação referem-se a um conjunto de diretrizes e procedimentos estabelecidos para proteger dados contra acessos não autorizados, violações e outros riscos. Essas práticas garantem a integridade, confidencialidade e disponibilidade das informações.

#### 3.1.6.7 Qual o período de armazenamento dos dados (retenção) <a id="c3-1-6-7"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Reteremos os Dados Pessoais pelo período correspondente ao tempo em que o titular manteve vínculo com o Instituto Apontar, acrescido de mais 60 meses (5 anos) após o término dessa relação, para cumprir as finalidades para as quais os dados foram coletados, conforme descrito nesta Política de Privacidade. Esse prazo é aplicado a menos que um período de retenção mais longo seja exigido por lei.

#### 3.1.6.8 Uso de cookies e/ou tecnologias semelhantes <a id="c3-1-6-8"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Podemos usar cookies, web beacons, pixel tags, log files, objetos locais compartilhados (flash cookies), ferramentas de análise e outras tecnologias de coleta automática de dados para coletar, armazenar e analisar certas informações.

#### 3.1.6.9 Com quem esses dados são compartilhados (parceiros, fornecedores, subcontratados) <a id="c3-1-6-9"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nós poderemos compartilhar seus Dados Pessoais:

- Com a(s) empresa(s) parceira(s) que você selecionar ou optar em enviar os seus dados, dúvidas, perguntas, etc, bem como com provedores de serviços ou parceiros para gerenciar ou suportar certos aspectos de nossas operações comerciais em nosso nome. Esses provedores de serviços ou parceiros podem estar localizados nos Estados Unidos, na Argentina, no Brasil ou em outros locais globais, incluindo servidores para homologação e produção, e prestadores de serviços de hospedagem e armazenamento de dados, gerenciamento de fraudes, suporte ao cliente, personalização de conteúdo, atividades de publicidade e marketing (incluindo publicidade digital e personalizada) e serviços de educação, por exemplo;
- Com terceiros, com o objetivo de nos ajudar a gerenciar a empresa;
- Para atender a solicitações de autoridades públicas e governamentais, bem como atender a exigências de órgãos regulatórios, processos judiciais ou quando a lei assim o exigir;
- Para outras finalidades, com o seu consentimento específico e prévio.

#### 3.1.6.10 Informações sobre medidas de segurança adotadas pela empresa <a id="c3-1-6-10"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Implementamos medidas técnicas e organizacionais apropriadas para proteger os Dados Pessoais que coletamos e tratamos. As medidas que usamos são projetadas para fornecer um nível de segurança adequado ao risco de Tratamento de seus Dados Pessoais e incluem procedimentos e diretrizes para assegurar a proteção de seus dados, medidas tecnológicas para mitigar riscos cibernéticos, proteção contra acesso não autorizado, uso indevido e divulgação, bem como medidas de proteção contra perda, alteração ou destruição de Dados Pessoais.

#### 3.1.6.11 Orientações sobre como a empresa/organização atende aos direitos dos usuários <a id="c3-1-6-11"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Respeitamos os direitos de privacidade e proteção de dados e estamos empenhados em cumprir a legislação aplicável. Conforme previsto na LGPD, você tem o direito de:

- Confirmar a existência de Tratamento de Dados Pessoais;
- Acessar seus Dados Pessoais;
- Corrigir Dados Pessoais incompletos, inexatos ou desatualizados;
- Solicitar a anonimização, bloqueio ou eliminação de Dados Pessoais desnecessários, excessivos ou tratados em desconformidade com a legislação;
- Solicitar a portabilidade de seus Dados Pessoais a outro fornecedor de serviço ou produto, mediante requisição expressa e observados os segredos comercial e industrial, de acordo com a regulamentação do órgão controlador;
- Eliminar Dados Pessoais tratados com seu consentimento, na medida do permitido em lei;
- Obter informações sobre as entidades públicas ou privadas com as quais compartilhamos seus Dados Pessoais;
- Obter informações sobre a possibilidade de não fornecer o seu consentimento e sobre as consequências dessa negativa;
- Revogar seu consentimento, quando o Tratamento de Dados Pessoais for baseado no consentimento, na forma da lei.

#### 3.1.6.12 Informações sobre como o titular de dados pode solicitar e exercer os seus direitos <a id="c3-1-6-12"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Caso deseje exercer algum desses direitos, entre em contato conosco. Responderemos a sua solicitação conforme exigido pela legislação aplicável.

#### Mudanças na Política de Privacidade

&nbsp;&nbsp;&nbsp;&nbsp;Podemos alterar esta Política de Privacidade a qualquer momento. Quando o fizermos, publicaremos a Política de Privacidade atualizada na instituição e informaremos pelo meio de contato de preferência. Recomendamos que você revise a Política de Privacidade periodicamente para se manter informado sobre como estamos protegendo seus dados.

#### 3.1.6.13 Informações de contato do Data Protection Officer (DPO) ou encarregado de proteção de dados da organização <a id="c3-1-6-13"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Se você tiver qualquer dúvida sobre esta Política de Privacidade ou nossas práticas de privacidade, entre em contato com nosso DPO (Data Protection Officer).<br>
LinkedIn do 'Head of Legal and Privacy Officer': [Linkedin Romulo Nunes](https://linkedin.com/in/romulo-nunes-505010135/)
<br>(Acesso em: 21 out. 2024).

**Estamos à disposição para quaisquer esclarecimentos adicionais e agradeço pela confiança na Exodia.**

&nbsp;&nbsp;&nbsp;&nbsp;A Política de Privacidade da Exodia, desenvolvida em conjunto com o Instituto Apontar, tem como objetivo principal assegurar a proteção dos dados pessoais de nossos usuários, de acordo com a Lei Geral de Proteção de Dados Pessoais (LGPD). O nosso objetivo é assegurar que as informações sejam tratadas de forma transparente e segura, seguindo as normas legais vigentes. Dessa forma, queremos aumentar a confiança dos usuários, demonstrando nosso empenho em proteger seus dados e respeitar os direitos de cada um.

### 3.1.7. Bill of Material (BOM)<a id="c3-1-7"></a>

&nbsp;&nbsp;&nbsp;&nbsp;A BOM consiste em uma lista de materiais, da qual descreve todos os materiais que serão utilizados na construção do produto. A lista geralmente é dividida em tópicos, representando algumas características e informações sobre cada produto, nesse caso, os seguintes tópicos estão sendo utilizados:

- **ID do Item**: Valor numérico único para identificar o item
- **Descrição do Item:** Nome e descrição do componente
- **Código do Item:** Código utilizado para identificar o item em um contexto industrial
- **Quantidade:** Quantidade necessária de cada item
- **Unidade:** Unidade de medida da quantidade de cada item (unidades, metros, etc)
- **Custo unitário:** Custo financeiro de cada unidade do item
- **Custo total:** Custo financeiro total do item (quantidade multiplicada pelo custo unitário)

#### Bill of Material do Protótipo de Leitura

&nbsp;&nbsp;&nbsp;&nbsp;Esse protótipo foi desenvolvido para realizar a leitura de dados de identificação, utilizando sensores e dispositivos específicos. Sendo importante para capturar informações que possibilitem a autenticação ou identificação dos usuários.

<div align="center">
<sub>Quadro 02 - Bill of Material do Protótipo de Leitura</sub>
</div>

| ID do Item | Descrição do Item                               | Quantidade | Custo Total | Link do Produto |
| ---------- | ----------------------------------------------- | -------------------- | ----------- | --------------- |
| 1          | Placa de Desenvolvimento ESP32-DevKitC WROOM-32 | 1 Unidade            | R$62,00     | [Fermarc](https://www.fermarc.com/esp32-devkitc-wroom-32d?srsltid=AfmBOoo-GA4yBfwTPg_cmkRGuWeVReY_qTws8LUI4H9R6yIpHl6ua6pN) |
| 2          | 2.4GHz PCB Antenna for ESP32 with IPEX connector| 1 Unidade            | R$28,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-1781256495-antena-para-esp32-cam-24gb-wireless-com-cabo-conector-ipex-_JM?matt_tool=40343894&matt_word=&matt_source=google&matt_campaign_id=14303413655&matt_ad_group_id=133855953276&matt_match_type=&matt_network=g&matt_device=c&matt_creative=584156655519&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=393598961&matt_product_id=MLB1781256495&matt_product_partition_id=2268053647590&matt_target_id=pla-2268053647590&cq_src=google_ads&cq_cmp=14303413655&cq_net=g&cq_plt=gp&cq_med=pla&gad_source=1&gclid=Cj0KCQiAgdC6BhCgARIsAPWNWH3aQkro_YyYhOm9x5VYdUAmycyBIIjL7ZyVVnjoQC6YmBEarJCnqWsaApiREALw_wcB) |
| 3          | Módulo Sensor Leitor Biométrico DY50            | 1 Unidade            | R$133,00    | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3803057663-modulo-sensor-leitor-biometrico-de-impresso-digital-arduino-_JM?matt_product_partition_id=2268053647590&matt_campaign_id=14303413655&matt_merchant_id=672419760&matt_network=g&matt_target_id=pla-2268053647590&matt_tool=40343894&gclid=CjwKCAiA34S7BhAtEiwACZzv4SbyIijfcldGwq1XpjTUwaWXJJGKAsvstW47dEH8UgU9JHbBsOseoRoC3mEQAvD_BwE&matt_creative=584156655519&matt_source=google&matt_ad_group_id=133855953276&matt_device=c&matt_product_id=MLB3803057663&from=gshop&matt_ad_type=pla#reco_backend=item_decorator&polycard_client=recommendations_home_items-pom-decorator&reco_client=home_items-pom-decorator&reco_item_pos=0&reco_backend_type=function&reco_id=6f366187-78d3-4e60-9dfe-e794c2b3e8e4&c_id=/home/card-featured/element&c_uid=3ea95b51-bc56-40df-9026-7a4f31ae36e4) |
| 4          | Módulo RFID MFRC522 13.56 Mhz                   | 1 Unidade            | R$20,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-1614899699-kit-modulo-leitor-gravador-rfid-mfrc522-1356mhz-arduino-_JM#polycard_client=search-nordic&position=4&search_layout=grid&type=item&tracking_id=ca4e887a-d02e-493e-b794-95950f4ba8ef) |
| 5          | Led RGB                                         | 1 Unidade            | R$11,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3647359820-10-x-led-difuso-rgb-5mm-anodo-comum-_JM?searchVariation=177747827464#polycard_client=search-nordic&searchVariation=177747827464&position=10&search_layout=grid&type=item&tracking_id=32cd7963-89ae-4202-8d49-7b73f8543f34) |
| 6          | Buzzer                                          | 1 Unidade            | R$11,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3147129820-buzzer-ativo-continuo-5v-para-esp8266-p-arduino-_JM#polycard_client=search-nordic&position=16&search_layout=grid&type=item&tracking_id=e26a2e19-e2d5-42af-a61f-74188773f782) |
| 7          | Display LCD 16x2 Serial + Módulo I2C            | 1 Unidade            | R$30,00     | [Eletrogate](https://www.eletrogate.com/display-lcd-16x2-i2c-backlight-azul?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant&utm_source=google&utm_medium=cpc&utm_campaign=[MC4]_[G]_[PMax]_Categorias&utm_content=&utm_term=&gad_source=1&gclid=Cj0KCQiA3sq6BhD2ARIsAJ8MRwVk6dlbFHl8mJol70vlz3teFn-KvCzgf9NswdyxZSLwn3bvOMlKMiMaAsWLEALw_wcB) |
| 8          | Módulo Relé 1 Canal 5V                          | 1 Unidade            | R$7,00      | [Eletrogate](https://www.eletrogate.com/modulo-rele-1-canal-5v?srsltid=AfmBOoo_xr0HQb9NXEZf-WUUSBiZ4D114BYFuJq9SyXrlJU5pzyhfF4E) |
| 9          | Mini Trava Fechadura Solenoide Eletrônica 12V   | 1 Unidade            | R$44,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-2755339438-mini-fechadura-solenoide-eletrnica-12v-350ma-para-arduino-_JM#polycard_client=recommendations_vip-v2p&reco_backend=ranker_retrieval_system_vpp_v2p&reco_model=ranker_entity_v2&reco_client=vip-v2p&reco_item_pos=1&reco_backend_type=low_level&reco_id=3a8cee2b-d039-491d-a74f-1b01179b06b7) |
| 10         | Chave Táctil Push-Button 4.3 mm                 | 1 Unidade            | R$1,00      | [Eletrônica Ômega](https://www.eletronicaomega.com/push-button-chave-tactil-6x6x6mm?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant&gad_source=1&gclid=Cj0KCQiApNW6BhD5ARIsACmEbkUMlIMSAyOqgP4Jt4vDYsGkSR4ELzVvlOvECKRVOqdIjRmFZjojUEQaAk-nEALw_wcB) |
| 11         | LED Difuso 10mm Azul                            | 1 Unidade            | R$1,00      | [A2 Robotics](https://www.a2robotics.com.br/led-difuso-10mm-azul?utm_source=Site&utm_medium=GoogleShopping&utm_campaign=IntegracaoGoogle&gad_source=1&gclid=Cj0KCQiApNW6BhD5ARIsACmEbkUtixLWymnjITmj1BXaZrOeUOzKtgGQ2zGL3BdET2L4mmVV5_Gw3JMaAkXHEALw_wcB) |

<!--| 10          | Módulo Micro SD Card                            | SD-003         | 1          | Unidades | R$30,00        | R$30,00       |-->

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

**Valor Total do BOM de Leitura:** R$348,00

#### Bill of Material do Protótipo de Cadastro

&nbsp;&nbsp;&nbsp;&nbsp;No desenvolvimento deste projeto, o grupo entendeu a necessidade de um protótipo adicional para a funcionalidade de cadastro, com isso, foi feita a listagem de outro BOM. Portanto, o segundo protótipo foi projetado para realizar o cadastro inicial dos usuários ou dispositivos, registrando os dados no sistema.

<div align="center">
<sub>Quadro 03 - Bill of Material do Protótipo de cadastro</sub>
</div>

| ID do Item | Descrição do Item                               | Quantidade | Custo Total | Link do Produto |
| ---------- | ----------------------------------------------- | -------------------- | ----------- | --------------- |
| 1          | Placa de Desenvolvimento ESP32-DevKitC WROOM-32 | 1 Unidade            | R$62,00     | [Fermarc](https://www.fermarc.com/esp32-devkitc-wroom-32d?srsltid=AfmBOoo-GA4yBfwTPg_cmkRGuWeVReY_qTws8LUI4H9R6yIpHl6ua6pN) |
| 2          | 2.4GHz PCB Antenna for ESP32 with IPEX connector| 1 Unidade            | R$28,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-1781256495-antena-para-esp32-cam-24gb-wireless-com-cabo-conector-ipex-_JM?matt_tool=40343894&matt_word=&matt_source=google&matt_campaign_id=14303413655&matt_ad_group_id=133855953276&matt_match_type=&matt_network=g&matt_device=c&matt_creative=584156655519&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=393598961&matt_product_id=MLB1781256495&matt_product_partition_id=2268053647590&matt_target_id=pla-2268053647590&cq_src=google_ads&cq_cmp=14303413655&cq_net=g&cq_plt=gp&cq_med=pla&gad_source=1&gclid=Cj0KCQiAgdC6BhCgARIsAPWNWH3aQkro_YyYhOm9x5VYdUAmycyBIIjL7ZyVVnjoQC6YmBEarJCnqWsaApiREALw_wcB) |
| 3          | Módulo Sensor Leitor Biométrico DY50            | 1 Unidade            | R$133,00    | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3803057663-modulo-sensor-leitor-biometrico-de-impresso-digital-arduino-_JM?matt_product_partition_id=2268053647590&matt_campaign_id=14303413655&matt_merchant_id=672419760&matt_network=g&matt_target_id=pla-2268053647590&matt_tool=40343894&gclid=CjwKCAiA34S7BhAtEiwACZzv4SbyIijfcldGwq1XpjTUwaWXJJGKAsvstW47dEH8UgU9JHbBsOseoRoC3mEQAvD_BwE) |
| 4          | Módulo RFID MFRC522 13.56 Mhz                   | 1 Unidade            | R$20,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-1614899699-kit-modulo-leitor-gravador-rfid-mfrc522-1356mhz-arduino-_JM) |
| 5          | Led RGB                                         | 1 Unidade            | R$11,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3647359820-10-x-led-difuso-rgb-5mm-anodo-comum-_JM) |
| 6          | Buzzer                                          | 1 Unidade            | R$11,00     | [Mercado Livre](https://produto.mercadolivre.com.br/MLB-3147129820-buzzer-ativo-continuo-5v-para-esp8266-p-arduino-_JM) |
| 7          | Display LCD 16x2 Serial + Módulo I2C            | 1 Unidade            | R$30,00     | [Eletrogate](https://www.eletrogate.com/display-lcd-16x2-i2c-backlight-azul) |
| 8          | Chave Táctil Push-Button 4.3 mm                 | 1 Unidade            | R$1,00      | [Eletrônica Ômega](https://www.eletronicaomega.com/push-button-chave-tactil-6x6x6mm) |
| 9          | LED Difuso 10mm Azul                            | 1 Unidade            | R$1,00      | [A2 Robotics](https://www.a2robotics.com.br/led-difuso-10mm-azul) |
<!--| 8          | Módulo Micro SD Card                            | SD-003         | 1          | Unidades | R$30,00        | R$30,00       |-->

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

**Valor Total do BOM de Cadastro:** R$297,00

&nbsp;&nbsp;&nbsp;&nbsp;A criação de dois protótipos independentes, porém complementares, foi necessário para atender às necessidades do projeto, otimizando processos e assegurando uma experiência funcional ao Instituto. O detalhamento da BOM para ambos os protótipos reforça a viabilidade técnica e financeira do sistema, além de proporcionar uma base para futuras expansões ou ajustes, caso necessário.

&nbsp;&nbsp;&nbsp;&nbsp;Com base nos materiais descritos, o custo total estimado para o desenvolvimento dos protótipos de leitura e cadastro é de R$645,00. Este investimento cobre os componentes para garantir a funcionalidade dos sistemas, incluindo sensores, módulos de controle e dispositivos de entrada e saída.

&nbsp;&nbsp;&nbsp;&nbsp;Os protótipos foram projetados com componentes de fácil integração e ampla compatibilidade, o que facilita a implementação e manutenção. Além disso, a escolha de itens acessíveis e de qualidade contribui para um projeto eficiente e econômico, mantendo o equilíbrio entre desempenho e custo.

## 3.2. Domínio de Fundamentos de Experiência de Usuário <a id="c3-2"></a>

### 3.2.1. Personas <a id="c3-2-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Uma persona é uma representação de um cliente ou usuário típico de um produto ou serviço. Em vez de imaginar o público como um grupo indefinido, empresas e equipes criam essas personas para entender melhor quem, exatamente, estão tentando alcançar. Cada persona é criada com base em informações reais, como idade, profissão, interesses e desafios comuns que esse público enfrenta.

&nbsp;&nbsp;&nbsp;&nbsp;As personas ajudam a equipe a tomar decisões mais eficientes, pois, ao desenvolver campanhas de marketing ou produtos, é possível pensar diretamente nesse "cliente modelo" e avaliar se a proposta é útil e atrativa para ele. Dessa forma, as personas tornam tudo mais direcionado e claro, garantindo que o público certo se conecte com o que está sendo oferecido. Em nosso caso, a persona ajudará a formar o melhor produto para nosso cliente, o instituto apontar, nós direcionando a como sanar as dores que estão enfrentando.

<div align="center">
<sub>Figura 7 - Persona Lucina</sub>
<img src="assets\personas\persona_lucina.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Lucina é uma das principais personas e a que será afetada pelo projeto, porque o foco do projeto é registrar a presença dos alunos no prédio e suas faltas, e a Lucina é a representação desses alunos. Ela tem problemas com atrasos e falta de informação sobre as aulas. Por isso, o produto precisa ser fácil de usar e confiável, evitando erros que prejudiquem seu desempenho. É importante que o sistema funcione bem e rápido para não gerar frustração ou ansiedade, especialmente para alunos que precisam de um ambiente escolar bem organizado. Lucina perdia seu cartão de entrada, o que a atrasava para entrar no prédio e criava uma inconveniência para conseguir um novo ou achar o perdido. A próxima persona é uma representação dos professores/orientadores do instituto que tem um papel vital no Instituto e utilizarão o produto. 

<div align="center">
<sub>Figura 8 - Persona Eduarda</sub>
<img src="assets\personas\persona_eduarda.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Eduarda, como professora, é essencial para o projeto e a principal persona que fará uso da nossa solução. Ela vai usar o sistema para acompanhar a presença dos alunos e garantir que participem das aulas. O sistema precisa ser rápido e fácil de usar, ajudando Eduarda a identificar alunos faltosos e agir, isso também, facilita a comunicação com os pais. Simplificar o acesso aos dados e enviar notificações automáticas sobre faltas são pontos importantes para atender suas necessidades. A próxima persona é uma representação dos responsáveis dentro do instituto de instalar e fazer a manutenção do produto dentro do Instituto. 

<div align="center">
<sub>Figura 9 - Persona Leonardo</sub>
<img src="assets\personas\persona_leonardo.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;A persona do Leonardo foi incluída pensando futuramente na instalação do produto; portanto, essa persona não se encaixa no contexto inicial do projeto, tendo menor prioridade no momento. Como coordenador, ele foi adicionado para garantir que a instalação e manutenção do sistema sejam feitas de forma eficiente. Ele é responsável pelo monitoramento contínuo e a manutenção simples, irá assegurar o funcionamento correto do sistema sem comprometer a segurança dos dados. Além disso, para facilitar a manutenção o sistema deve facilitar diagnósticos rápidos em caso de problemas técnicos. O sistema também continuará a funcionar caso a internet caia, salvando a presença dos alunos e registrando-a quando for capaz de se conectar novamente. Com as digitais registradas no sistema, o produto não precisa estar conectado à internet para funcionar.


#### Conclusão: 
&nbsp;&nbsp;&nbsp;&nbsp;Estas personas foram criadas a partir de informações no site oficial, conversas com funcionários do Instituto Apontar e vídeos disponíveis no canal do instituto, incluindo um mini documentário de 1 hora sobre o projeto Lic. A partir da análise dessas conversas e vídeos, foram elaboradas personas baseadas em dados reais, que refletem as necessidades, desafios e motivações dos usuários, proporcionando uma compreensão mais profunda do perfil de nossos clientes.

&nbsp;&nbsp;&nbsp;&nbsp;Em resumo, Lucina e Eduarda são as personas centrais para o sucesso do projeto, pois suas necessidades dependem diretamente do bom funcionamento do sistema. Para Lucina, o foco está em garantir que o sistema seja prático, confiável e intuitivo, ajudando a evitar atrasos e garantindo acesso contínuo em suas aulas. Para Eduarda, o sistema deve ser uma ferramenta eficiente que permita monitorar a presença dos alunos, identificar faltas rapidamente e facilitar a comunicação com os pais. Enquanto Leonardo tem uma prioridade menor no contexto inicial, sua atuação será essencial no futuro para garantir a integração e manutenção do sistema, assegurando que ele siga as normas de segurança e proteção de dados. Cada persona traz demandas específicas que moldam tanto o desenvolvimento quanto a implementação, garantindo que o produto atenda a todos os envolvidos de forma eficiente.

### 3.2.2. Jornada do Usuário e Storyboard 	<a id="c3-2-2"></a>
&nbsp;&nbsp;&nbsp;&nbsp;A Jornada do Usuário visa representar o caminho que um usuário percorre ao interagir com um produto ou serviço, desde o primeiro contato até a conclusão de suas necessidades. A formulação das jornadas é essencial para entender as experiências e os sentimentos dos usuários em cada etapa, permitindo identificar oportunidades de melhorar a eficácia dos produtos, serviços e suportes oferecidos. Além disso, possibilita a delimitação clara das responsabilidades da equipe em cada uma das etapas do processo.

#### Jornada de usuário Lucina Lima (Aluna):

&nbsp;&nbsp;&nbsp;&nbsp;Nessa jornada, a usuária Lucina Lima utiliza um sistema de controle de acesso e monitoramento de presença automatizado no Instituto Apontar. A análise da jornada de Lucina passa desde o interesse inicial pelo novo sistema até a sua adoção, considerando suas ações, sentimentos e emoções durante o processo. 

<div align="center">
<sub>Figura 10 - Jornada de usuário da Lucina (aluna)</sub>
<img src="..\document\assets\business\jornadalucina.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;A jornada de Lucina começa com sua insatisfação em relação ao método tradicional de controle de acesso do Instituto, que gera demora e atrapalha sua rotina diária, especialmente quando ela precisa chegar no horário. Essa insatisfação desperta seu interesse em uma solução que possa agilizar o acesso ao prédio e fornecer um registro de suas faltas.

&nbsp;&nbsp;&nbsp;&nbsp;Ao buscar alternativas para facilitar seu dia a dia, Lucina demonstra otimismo, imaginando que uma nova tecnologia poderia agilizar e muito o seu acesso ao Instituto. 

&nbsp;&nbsp;&nbsp;&nbsp;Com a implementação do novo sistema, Lucina começa a utilizá-lo e rapidamente percebe seus benefícios em comparação com o método anterior. Ela fica impressionada com a praticidade do sistema, que automatiza seu acesso e registra automaticamente sua presença. Ao notar essa mudança positiva, Lucina se sente aliviada e satisfeita, enxergando o impacto direto em sua rotina e nos processos do Instituto.

&nbsp;&nbsp;&nbsp;&nbsp;Essa análise da jornada de Lucina demonstra como o novo sistema atende suas expectativas e necessidades, proporcionando uma experiência positiva desde o primeiro contato até a adesão. Ao entender cada fase da jornada, o Instituto Apontar pode continuar aprimorando o sistema, garantindo que ele seja intuitivo, eficiente e mantenha a praticidade que é o que prezamos.

#### Jornada de usuário Eduarda Batista (coordenadora/professora):

&nbsp;&nbsp;&nbsp;&nbsp;A jornada da usuária Eduarda ilustra um cenário em que ela utiliza uma aplicação para monitorar a presença dos alunos. A análise da jornada de Eduarda abrange desde a curiosidade inicial sobre as presenças até a adesão final ao sistema, considerando tanto suas ações dentro da aplicação quanto os sentimentos que ela experimenta ao longo do processo. Sua jornada foi criada baseada em reuniões com o parceiro, Instituto Apontar, e da documentação do TAPI.

<div align="center">
<sub>Figura 11 - Jornada de usuária Eduarda (coordenadora/professora)</sub>
<img src="..\document\assets\business\jornadaeduarda.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;A jornada de Eduarda começa com o interesse em usar a nova aplicação trazida para o instituto, que promete automatizar a checagem da presença dos alunos. Logo após acessar e entender o produto, Eduarda quer verificar a presença dos alunos logo após o horário de entrada. Ela acessa a aplicação e observa o estado atual das presenças, o que possibilita à equipe instalar um sistema de notificação para alunos com pouca presença. Em seguida, ao navegar pela interface, Eduarda realiza buscas para identificar alunos com altas taxas de ausência. Conforme Eduarda identifica padrões de faltas, ela demonstra uma preocupação com os alunos ausentes, o que sugere a necessidade de filtros e ferramentas que facilitem a visualização desses casos.

&nbsp;&nbsp;&nbsp;&nbsp;Ao prosseguir, Eduarda encontra uma solução ao obter as informações de contato dos responsáveis, o que a tranquiliza e possibilita uma comunicação eficiente. Esse momento sublinha a relevância de uma funcionalidade que permita interagir diretamente com os responsáveis, otimizando o processo de monitoramento. Após realizar essas ações e notar o impacto positivo da aplicação. Nesse ponto, destaca-se a oportunidade de expandir a usabilidade do produto, incluindo gráficos e relatórios automáticos que aprimorem o entendimento dos dados de presença.

&nbsp;&nbsp;&nbsp;&nbsp;Ao avançar na jornada, Eduarda se tranquiliza ao acessar as informações de contato dos responsáveis pelos alunos, o que facilita uma comunicação direta e eficaz. Esse ponto evidencia a importância de uma funcionalidade que permita interação com os responsáveis, simplificando o monitoramento de presença. Após utilizar essa solução e perceber seu impacto positivo, Eduarda reflete sobre a praticidade e eficiência da ferramenta, levando a uma adoção consolidada do produto. Aqui, destaca-se a oportunidade de aprimorar o produto, incorporando gráficos e relatórios automáticos que tornem a análise de dados de presença mais intuitiva e acessível.

&nbsp;&nbsp;&nbsp;&nbsp;A jornada auxilia também a criação de story boards, já que ambas tentam retratar a realidade geral dos usuários e clientes do produto. Por sua semelhança em propósito, entender como será usado o produto, pode-se encontrar etapas parecidas como a de checar a presença dos alunos e entrar em contato com seus responsáveis.

&nbsp;&nbsp;&nbsp;&nbsp;Compreender a jornada do usuário é essencial para aprimorar sua experiência, alinhando o produto ou serviço às suas necessidades, expectativas e emoções em cada etapa. No caso de Eduarda, cada fase da jornada revela como ela utiliza a ferramenta para monitorar a presença dos alunos, além de destacar os sentimentos que surgem ao longo do processo, desde a busca inicial até a adesão final. Ao focar nas responsabilidades e nas oportunidades identificadas nessa jornada, a empresa pode não só melhorar a funcionalidade e usabilidade do produto, mas também fortalecer a confiança e a satisfação de Eduarda, proporcionando uma solução mais completa e intuitiva que atende às suas demandas e facilita seu trabalho.

#### Jornada de usuário Leonardo Mateus (coordenador):

&nbsp;&nbsp;&nbsp;&nbsp;A jornada do usuário Leonardo ilustra um cenário em que ele utiliza uma aplicação para monitorar a presença dos alunos e colaboradores do instituto. A análise da jornada de Leonardo abrange desde seu interesse inicial em compreender os padrões de frequência até a completa adesão ao sistema, considerando tanto suas interações com a aplicação quanto suas reações emocionais durante o processo. Sua jornada foi criada baseada em reuniões com o parceiro, Instituto Apontar, e da documentação do TAPI.

<div align="center">
<sub>Figura 12 - Jornada de usuário Leonardo (coordenador)</sub>
<img src="..\document\assets\business\jornadaleonardo.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Inicia-se com seu desejo de analisar a média de tempo de permanência dos alunos e colaboradores no instituto. Demonstrando curiosidade sobre os dados de presença, ele acessa a interface para visualizar as estatísticas gerais de frequência. Durante sua exploração, Leonardo consegue identificar importantes padrões de comportamento, notando que diversos membros não estão comparecendo ao instituto regularmente. Esta descoberta o leva a uma análise mais aprofundada dos dados, destacando a necessidade de ferramentas de filtragem mais robustas para identificar casos específicos.

&nbsp;&nbsp;&nbsp;&nbsp;Ao prosseguir com sua análise, Leonardo experimenta um sentimento de alívio ao conseguir solucionar o problema de identificação das ausências. O sistema permite que ele mantenha as informações de contato dos ausentes facilmente acessíveis, o que otimiza o processo de acompanhamento. Este momento evidencia a importância de manter dados de contato organizados e prontamente disponíveis, facilitando ações corretivas quando necessário.

&nbsp;&nbsp;&nbsp;&nbsp;Na fase final de sua jornada, Leonardo demonstra entusiasmo ao comparar a precisão dos novos dados com suas antigas planilhas de controle. A eficiência do sistema automatizado o motiva a expandir sua utilização para todas as áreas do instituto, visando um controle mais abrangente da permanência nas diferentes salas. Este momento ressalta a oportunidade de implementar recursos adicionais, como gráficos de métricas e um manual de instruções detalhado para solução de problemas, tornando o sistema ainda mais robusto e útil para todos os usuários.

&nbsp;&nbsp;&nbsp;&nbsp;A jornada de Leonardo contribui significativamente para o desenvolvimento dos story boards, pois oferece uma perspectiva administrativa do uso do sistema. Sua experiência destaca aspectos cruciais como a necessidade de ferramentas analíticas avançadas, a importância da precisão dos dados e o valor de um suporte técnico adequado, elementos essenciais para o sucesso contínuo do produto no ambiente institucional.

#### Conclusão:
&nbsp;&nbsp;&nbsp;&nbsp;A análise detalhada das jornadas de Lucina, Eduarda e Leonardo demonstra que o sistema de monitoramento de presença atende efetivamente às necessidades fundamentais dos usuários do Instituto Apontar. O produto não apenas automatiza processos anteriormente manuais, mas também oferece recursos valiosos para análise de dados e tomada de decisões, como evidenciado pela progressão emocional positiva dos usuários ao longo de suas interações com o sistema.
&nbsp;&nbsp;&nbsp;&nbsp;A satisfação demonstrada pelos usuários em suas jornadas, especialmente na fase de adesão, confirma o sucesso do produto em cumprir sua proposta de valor. As oportunidades identificadas, como a implementação de sistemas de notificação, ferramentas de filtro avançadas e recursos de visualização de dados, apontam caminhos claros para a evolução contínua do sistema. Essas melhorias potenciais não apenas enriquecerão a experiência atual dos usuários, mas também garantirão que o sistema permaneça adaptável e escalável para atender às necessidades futuras do Instituto Apontar.

### 3.2.3. Storyboards <a id="c3-2-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O storyboard é uma sequência de desenhos quadro a quadro com o esboço das diversas cenas pensadas para um conteúdo em vídeo. O visual desse esboço é semelhante ao de uma história em quadrinhos e o objetivo é elaborar e detalhar a sequência da narrativa. Essa ferramenta é originalmente utilizada em animações, filmes e jogos, mas com o passar do tempo, tornou-se muito aplicada também em projetos gráficos para publicidade e marketing. <br>

&nbsp;&nbsp;&nbsp;&nbsp;As storyboards a seguir foram desenvolvidas a mão com base nas personas descritas na seção 3.2.1, destacando a realidade e desafios enfrentados por cada uma delas no contexto do Instituto. Cada sequência aborda o cotidiano das personas antes da solução e as melhorias que a implementação trouxe.

#### Storyboard Aluna

<div align="center">
<sub>Figura 13 - Storyboard da aluna (Luciana)</sub>
<img src="../document\assets\storyboards\storyboard_aluna.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

#### Storyboard Professora

<div align="center">
<sub>Figura 14 - Storyboard da professora (Eduarda)</sub>
<img src="..\document\assets\storyboards\storyboard_professora.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

#### Storyboard Coordenador

<div align="center">
<sub>Figura 15 - Storyboard do coordenador (Leonardo)</sub>
<img src="..\document\assets\storyboards\storyboard_coordenador.png" width="100%" >
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Através dos storyboards apresentados, é possível visualizar as dificuldades enfrentadas pelas personas Lucina, Eduarda e Leonardo antes da implementação da nossa solução e os significativos avanços obtidos após sua adoção. Cada sequência de quadrinhos evidencia, de maneira prática e visual, como a solução transformou o dia a dia dos usuários. Essas ilustrações não apenas ressaltam os benefícios da implementação, mas também reforçam o valor da solução na promoção de um ambiente de aprendizado mais organizado e acessível. O uso do storyboard possibilita um entendimento claro e intuitivo do impacto da tecnologia aplicada, evidenciando como a solução melhora a experiência individual de cada persona e contribui para um sistema mais eficiente no instituto.

## 3.3. Solução Técnica	<a id="c3-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp;A solução técnica do projeto RedLock envolve uma combinação de hardware e software integrados para atender às necessidades de controle de acesso e monitoramento de frequência no Instituto Apontar. A seguir, detalhamos os principais componentes e funcionalidades que compõem a solução.

### 3.3.1. Requisitos Funcionais <a id="c3-3-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O projeto RedLock visa implementar um sistema de controle de acesso e monitoramento de presença no Instituto Apontar, utilizando sensores biométricos e de crachá. Os requisitos funcionais descritos a seguir foram elaborados para garantir que a solução eficiente e escalável, permitindo o controle de entrada de alunos e funcionários com base em dados biométricos e identificação por crachá.

&nbsp;&nbsp;&nbsp;&nbsp;Requisitos funcionais são descrições detalhadas das funcionalidades que o sistema deve oferecer para cumprir seus objetivos. Eles especificam o que o sistema deve fazer, as interações entre os componentes, e como os usuários utilizarão essas funcionalidades. Esses requisitos são essenciais para guiar o desenvolvimento da solução, garantindo que todos os processos necessários sejam contemplados e que o sistema atenda às expectativas dos usuários e da organização. A definição desses requisitos foi orientada pelas necessidades de usuários específicos (personas), garantindo que as funcionalidades atendam às demandas de todos os envolvidos no processo de controle de presença.

<br>
<div align="center">
<sub>Quadro 04 - Requisitos Funcionais </sub>
</div>

| **RF#** | **Descrição** | **Regra de negócio** | **Persona Atingida** |
|----------|----------|----------|--------|
| RF01 | O sistema deve permitir o cadastro de novos usuários (digitais e cartões RFID), para que os mesmos possam ser reconhecidos e autorizados na catraca. | Apenas usuários com permissões específicas podem realizar o cadastro de novos usuários no sistema. | Lucina, Eduarda e Leonardo | 
| RF02 | O sistema deve controlar a abertura e o fechamento da catraca de acordo com as permissões de cada usuário cadastrado. | Apenas usuários cadastrados e com acesso autorizado podem utilizar a catraca. | Lucina, Eduarda e Leonardo |
| RF03 | O sistema deve armazenar as informações dos dados de cadastro e registrar os horários de entrada e saída de cada usuário para controle de presença. | Os dados de entrada e saída devem ser armazenados para geração de relatórios de frequência. | Lucina, Eduarda e Leonardo | 
| RF04 | A solução deve oferecer uma interface com gráficos e filtros para visualização de dados de presença e frequência. | Apenas usuários autorizados podem visualizar os dados de presença. | Eduarda | 
| RF05 | A interface de visualização deve ter um sistema de cadastro, permitindo que apenas usuários autorizados pelo modelo de negócios acessem o sistema. | O sistema deve restringir o acesso às funcionalidades de visualização e cadastro apenas a usuários permitidos. | Eduarda e Leonardo | 
| RF06 | O sistema deve ser capaz de armazenar dados coletados em modo offline e sincronizá-los automaticamente com o banco de dados quando a conexão for restaurada. | A sincronização dos dados coletados offline deve ocorrer sem intervenção do usuário para garantir a atualização automática das informações. | Leonardo | 

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>

&nbsp;&nbsp;&nbsp;&nbsp;A partir desses requisitos, o sistema será capaz de operar de maneira segura, proporcionando uma gestão de entradas e presenças, facilitando o controle de alunos e funcionários. Ao definir as interações entre hardware e software, asseguramos que a solução seja escalável e possa ser adaptada a diferentes cenário.

### 3.3.2. Requisitos Não Funcionais 	<a id="c3-3-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Requisitos não funcionais são características que definem como o sistema deve operar, assegurando qualidade em aspectos como desempenho, usabilidade, confiabilidade, segurança, disponibilidade, manutenibilidade e as tecnologias envolvidas. Eles complementam os requisitos funcionais ao especificar padrões de operação que o sistema precisa alcançar para oferecer uma melhor aos usuários.

&nbsp;&nbsp;&nbsp;&nbsp;Esses requisitos englobam elementos como o tempo de resposta e eficiência (desempenho), facilidade de uso (usabilidade), proteção contra falhas e consistência dos dados (confiabilidade), e proteção de dados e privacidade (segurança). Além disso, os requisitos não funcionais asseguram que o sistema permaneça disponível e acessível, seja facilmente mantido e atualizado com novas tecnologias conforme necessário.

<br>
<div align="center">
<sub>Quadro 05 - Requisitos Não Funcionais </sub>
</div>

| **RNF#** | **Descrição** | **Aspecto de qualidade** | 
|----------|----------|----------|
|RNF01|O tempo para autenticação deve ser rápido o suficiente para garantir fluidez. Esse reconhecimento deve ser feito em menos de 3 segundos para não causar atrasos.| Desempenho |
|RNF02|O sistema deve ter acesso à internet para permitir a atualização das visualizações em tempo real.|Disponibilidade e Confiabilidade|
|RNF03|Deve ser implementado um led RGB, que exiba a luz vermelha quando o acesso for negado, e a luz verde quando for liberado.|Usabilidade|
|RNF04|Implementação de um buzzer para retorno sonoro quando o acesso for negado ou permitido.|Usabilidade|
|RNF05|Todos os dados biométricos coletados devem ser criptografados durante a transmissão ao backend.|Segurança|
|RNF06|O sistema deve permitir a atualização dos módulos de controle de acesso e sensores biométricos de forma independente, usando tecnologias padrão para facilitar a manutenção e futuras substituições.|Manutenibilidade e Atualização Tecnológica|

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>

### Casos de Teste dos RNF:

<br>
<div align="center">
<sub>Quadro 06 - Casos De Teste Requisitos Não Funcionais </sub>
</div>

| **#** | **Descrição** | **Pré-condição** | **Procedimento de teste** | **Pós-condição/Resultado esperado** | **Observações** (opcional) |
|-------|---------------|------------------|---------------------------|-------------------------------------|----------------------------|
| 01    | Verificação do tempo de autenticação | O sistema está configurado e pronto para autenticar. | Iniciar o processo de autenticação e medir o tempo até a conclusão. | A autenticação deve ser concluída em menos de 3 segundos. | - |
| 02    | Verificação de acesso à internet para atualizações em tempo real | O dispositivo está conectado à rede Wi-Fi. | Testar a atualização das visualizações em tempo real enquanto o dispositivo está online. | As visualizações devem ser atualizadas corretamente em tempo real. | - |
| 03    | Funcionamento do LED RGB | O sistema está configurado com o LED RGB. | Realizar tentativas de autenticação com sucesso e falha, e observar a cor do LED. | O LED deve acender em vermelho quando o acesso for negado e verde quando for liberado. | - |
| 04    | Funcionamento do buzzer | O sistema está configurado com o buzzer. | Realizar tentativas de autenticação bem-sucedida e falha e observar o som emitido pelo buzzer. | O buzzer deve emitir sons distintos para acesso negado e liberado. | - |
| 05    | Criptografia de dados biométricos | O sistema está configurado para capturar dados biométricos. | Capturar dados biométricos e monitorar a transmissão ao backend. | Os dados biométricos devem ser transmitidos de forma criptografada. | - |
| 06    | Atualização independente de módulos | O sistema está com os módulos de controle de acesso e sensores biométricos instalados. | Realizar a atualização de cada módulo separadamente e verificar se o outro módulo continua funcionando normalmente. | A atualização de cada módulo deve ser realizada de forma independente, sem afetar o outro. | - |

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>

### 3.3.3. Arquitetura da Solução <a id="c3-3-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O diagrama de arquitetura é uma representação visual que descreve a organização e as conexões entre os componentes de um sistema. Esses componentes podem incluir elementos de hardware, como microcontroladores, sensores, telas e motores, bem como elementos de software, como APIs, bancos de dados e interfaces web. A função principal do diagrama é proporcionar uma visão clara das interações e dependências entre os elementos do sistema. Ele facilita a compreensão do projeto como um todo, permitindo identificar dependências cruciais, como quais partes do sistema influenciam ou são influenciadas por outras, otimizando o processo de desenvolvimento e manutenção.

&nbsp;&nbsp;&nbsp;&nbsp;O diagrama a seguir está dividido em três áreas principais: Protótipo Físico, Back-End e Front-End. O Protótipo Físico representa todos os componentes de hardware do projeto, como o microcontrolador ESP32 e os sensores (biométrico e RFID). O Back-End inclui os componentes de software responsáveis pelo processamento central e armazenamento, como a API e o banco de dados. Por fim, o Front-End destaca os elementos relacionados à interface do usuário, incluindo o site que contém o dashboard para análise de dados e a plataforma de controle para administração do sistema. Essa organização modular facilita o entendimento das responsabilidades e interações de cada parte do sistema.

<div align="center">
<sub>Figura 16 - Diagrama de arquitetura</sub>
<img src="..\document\assets\arquitetura\diagrama_arquitetura.png" width="100%" >
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;A partir do diagrama de arquitetura, o grupo Exodia produziu um vídeo explicando individualmente cada detalhe do diagrama de arquitetura, visando complementar a explicação e facilitar o entendimento.
**Link:** <a href="https://youtu.be/qSM935gRzU4">Vídeo com a explicação da arquitetura</a>

&nbsp;&nbsp;&nbsp;&nbsp;A seguinte tabela, busca descrever como o diagrama de arquitetura suporta cada um dos requisitos funcionais e dos requisitos não funcionais.

Descrição das colunas da tabela:

- **ID:** Identificação do requisito funcional ou não funcional
- **Funcional?:** Coluna que visa identificar o requisito como funcional ou não funcional
- **Descrição do requisito:** Texto explicativo sobre o requisito
- **Como a arquitetura aborda?:** Explicação sobre como o diagrama de arquitetura aborda o requisito

<div align="center">
<sub>Quadro 07 - Quadro indicando como o diagrama de arquitetura aborda os requisitos</sub>
</div>

| **ID**  | **Funcional?** | **Descrição do requisito** | **Como a arquitetura aborda?** |
|---------|----------------|----------------------------|--------------------------------|
| RF01    | Sim            | O sistema deve permitir o cadastro de novos usuários (digitais e cartões RFID), para que os mesmos possam ser reconhecidos e autorizados na catraca. | Utiliza a API para registrar os dados dos usuários, com integração ao sensor biométrico e ao leitor RFID conectados ao ESP32. |
| RF02    | Sim            | O sistema deve controlar a abertura e o fechamento da catraca de acordo com as permissões de cada usuário cadastrado. | Através do ESP32, recebe dados dos sensores e realiza o controle de acesso, abrindo ou fechando portas ou catracas conforme as permissões. |
| RF03    | Sim            | O sistema deve armazenar as informações dos dados de cadastro e registrar os horários de entrada e saída de cada usuário para controle de presença. | O ESP32 envia os dados de entrada/saída para a API, que atualiza o banco de dados com logs detalhados. |
| RF04    | Sim            | A solução deve oferecer uma interface com gráficos e filtros para visualização de dados de presença e frequência. | O dashboard do front-end consome dados processados pela API e exibidos em gráficos e filtros dinâmicos. |
| RF05    | Sim            | A interface de visualização deve ter um sistema de cadastro, permitindo que apenas usuários autorizados pelo modelo de negócios acessem o sistema. | Implementação de autenticação na plataforma de controle, integrada à API para validação de permissões. |
| RF06    | Sim            | O sistema deve ser capaz de armazenar dados coletados em modo offline e sincronizá-los automaticamente com o banco de dados quando a conexão for restaurada. | O ESP32 armazena temporariamente os dados e utiliza MQTT Broker para sincronizar automaticamente quando a conexão é restabelecida. |
| RNF01   | Não            | O tempo para autenticação deve ser rápido o suficiente para garantir fluidez. Esse reconhecimento deve ser feito em menos de 3 segundos para não causar atrasos. | Armazena as informações necessárias para os reconhecimentos de forma offline, e tudo que é necessário para fazer o reconhecimento é conectado de forma cabeada, evitando conexões wireless e permitindo que o programa seja mais rápido e fluído |
| RNF02   | Não            | O sistema deve ter acesso à internet para permitir a atualização das visualizações em tempo real. | O ESP32 conecta-se ao MQTT Broker para envio e recebimento de dados em tempo real. |
| RNF03   | Não            | Deve ser implementado um LED RGB, que exiba a luz vermelha quando o acesso for negado, e a luz verde quando for liberado. | O LED RGB é acionado diretamente pelo ESP32, configurado para indicar os resultados da autenticação. |
| RNF04   | Não            | Implementação de um buzzer para retorno sonoro quando o acesso for negado ou permitido. | O buzzer é controlado pelo ESP32, emitindo sinais diferentes para cada tipo de resposta. |
| RNF05   | Não            | Todos os dados biométricos coletados devem ser criptografados durante a transmissão ao backend. | Utiliza comunicação segura via MQTT e criptografia HTTPS para transmissão dos dados biométricos à API. |
| RNF06   | Não            | O sistema deve permitir a atualização dos módulos de controle de acesso e sensores biométricos de forma independente, usando tecnologias padrão para facilitar a manutenção e futuras substituições. | A arquitetura modular do ESP32 permite atualizações e substituições independentes de sensores e módulos. |
<div align="center">
<sub>Fonte: Material produzido pelo grupo Exodia (2024)</sub>
</div>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;A arquitetura da solução do projeto RedLock integra os componentes de hardware, back-end e front-end para oferecer um sistema de controle de acesso e monitoramento de frequência. A combinação dos sensores biométricos e RFID com o ESP32 permite a captura precisa dos dados, enquanto a API e o banco de dados garantem o armazenamento e processamento dessas informações. A interface visual facilita a gestão em tempo real, atendendo aos requisitos funcionais e não funcionais definidos.

#### 3.3.3.1 Banco de dados <a id="c3-3-3-1"></a>
**Introdução**

&nbsp;&nbsp;&nbsp;&nbsp;Bancos de dados são fundamentais na ciência da computação, permitindo o armazenamento, organização e manipulação eficiente de informações. Neste projeto, utilizamos a modelagem relacional, um conceito amplamente empregado em sistemas de gerenciamento de banco de dados (SGBD), como MySQL, PostgreSQL e Oracle, devido à sua eficiência, flexibilidade e capacidade de garantir a integridade dos dados.

&nbsp;&nbsp;&nbsp;&nbsp;A modelagem relacional organiza os dados em tabelas, onde cada tabela representa uma entidade distinta e as relações entre elas são estabelecidas por meio de chaves primárias e chaves estrangeiras. Essa abordagem permite estruturar os dados de maneira clara, facilitando operações como inserção, atualização e consulta de informações.

&nbsp;&nbsp;&nbsp;&nbsp;No contexto deste projeto, o banco de dados relacional foi projetado no sistema PostgreSQL. Sua implementação permite gerenciar eficientemente as informações relacionadas às entidades e suas relações, atendendo aos requisitos de escalabilidade do sistema. Cada entidade é representada por uma tabela, e suas relações são cuidadosamente mapeadas para assegurar consistência e facilitar o acesso aos dados.

&nbsp;&nbsp;&nbsp;&nbsp;Embora o foco principal seja o modelo relacional, vale ressaltar que existem outras abordagens, como os bancos de dados não relacionais (NoSQL). Esses são ideais para cenários com dados altamente não estruturados, como big data ou redes sociais, mas não atendem tão bem a situações em que a consistência e o rigor das relações entre dados são essenciais.

&nbsp;&nbsp;&nbsp;&nbsp;Abaixo, encontra-se o diagrama do projeto (Figura 17):

<div align="center">
<sub>Figura 17 - Modelagem Relacional do Projeto</sub>
<img src="..\document\assets\banco de dados\modelagem.png" width="100%" >
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Este diagrama ilustra os relacionamentos entre as entidades do modelo relacional. Cada entidade é representada por um retângulo, e os relacionamentos são indicados por linhas conectando as entidades.

**Tabelas**

&nbsp;&nbsp;&nbsp;&nbsp;As tabelas definidas no projeto incluem: <br>
  - Tabela `permissao`: Contém os tipos de permissões dos usuários.<br>
  - Tabela `titulo_usuario`: Contém os títulos dos usuários (coordenador, professor, aluno, visitante).<br>
  - Tabela `permissao_titulo_usuario`: Relaciona as permissões com os títulos dos usuários.<br>
  - Tabela `acesso`: Contém os tipos de acesso existentes (biometria e cartão RFID).<br>
  - Tabela `usuario`: Armazena os dados pessoais dos usuários.<br>
  - Tabela `acesso_usuario`: Relaciona o tipo de acesso, o código HASH e o usuário.<br>
  - Tabela `atividade`: Armazena os tipos de atividades realizadas pelo Instituto.<br>
  - Tabela `local`: Armazena os locais onde as atividades serão realizadas.<br>
  - Tabela `evento`: Armazena informações sobre eventos do Instituto, como local, responsável e data.<br>
  - Tabela `usuario_atividade`: Relaciona os usuários com suas atividades específicas.<br>
  - Tabela `visita`: Armazena os dados das visitas realizadas no instituto, como data e hora, além de relacionar com os dados do visitante.<br>
  - Tabela `frequencia`: Armazena a frequência dos usuários, registrando os horários de interação com o dispositivo e a data.<br>

&nbsp;&nbsp;&nbsp;&nbsp;As tabelas que precisam armazenar informações já presentes em outras tabelas utilizam chaves estrangeiras (Foreign Keys). Isso significa que elas apenas armazenam o ID dessas informações, permitindo o relacionamento entre as tabelas.

**Diagrama de cada tabela**

1. Tabela `permissao` 
    - Identificação: id (chave primária).
    - Outras colunas: 
      - `tipo_permissao` (INTEGER) – Representa o tipo de permissão. 
    - Descrição: Armazena os diferentes tipos de permissões que podem ser atribuídas.

<div align="center">
<sub>Figura 18 - Modelagem da tabela permissao</sub><br>
<img src="..\document\assets\banco de dados\permissao.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

2. Tabela `titulo_usuario` 
    - Identificação: id (chave primária).
    - Outras colunas: 
      - `titulo` (VARCHAR, 100) – Título associado ao usuário.
    - Descrição: Define os diferentes títulos que um usuário pode possuir no sistema.

<div align="center">
<sub>Figura 19 - Modelagem da tabela titulo_usuario</sub><br>
<img src="..\document\assets\banco de dados\titulo_usuario.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

3. Tabela `permissao_titulo_usuario`
    - Identificação: id (chave primária).
    - Chaves estrangeiras:
      - `id_permissao` referenciando o ID da tabela `permissao`.
      - `id_titulo_usuario` referenciando o ID da tabela `titulo_usuario`.
    - Descrição: Relaciona as permissões com os títulos de usuários.

<div align="center">
<sub>xFigura 20 - Modelagem da tabela permissao_titulo_usuario</sub><br>
<img src="..\document\assets\banco de dados\permissao_titulo_usuario.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

4. Tabela `acesso`
    - Identificação: id (chave primária).
    - Outras colunas:
      - `forma_acesso` (INTEGER) – Representa o tipo de acesso.
    - Descrição: Registra os métodos de acesso disponíveis no sistema.

<div align="center">
<sub>Figura 21 - Modelagem da tabela acesso</sub><br>
<img src="..\document\assets\banco de dados\acesso.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

5. Tabela `usuario`
    - Identificação: id (chave primária).
    - Chaves estrangeiras:
      - `id_titulo_usuario` (INTEGER) – Relacionada o ID da tabela `titulo_usuario`.
    - Outras colunas:
      - `nome` (VARCHAR, 100) – Nome do usuário.
      - `cpf` (CHAR, 11) – CPF do usuário.
    - Descrição: Contém as informações pessoais dos usuários cadastrados no sistema.

<div align="center">
<sub>Figura 22 - Modelagem da tabela usuario</sub><br>
<img src="..\document\assets\banco de dados\usuario.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

6. Tabela `acesso_usuario`
    - Identificação: id (chave primária).
    - Chaves estrangeiras:
      - `id_acesso` referenciando o ID da tabela `acesso`.
      - `id_usuario` referenciando o ID da tabela `usuario`.
    - Outras colunas:
      - `codigo_acesso` (VARCHAR) – Código único de acesso do usuário.
    - Descrição: Registra as associações de usuários com os métodos de acesso.

<div align="center">
<sub>Figura 23 - Modelagem da tabela acesso_usuario</sub><br>
<img src="..\document\assets\banco de dados\acesso_usuario.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

7. Tabela `atividade`
    - Identificação: id (chave primária).
    - Outras colunas:
      - `tipo_atividade` (VARCHAR, 100) – Tipo da atividade.
    - Descrição: Armazena os diferentes tipos de atividades realizadas no sistema.

<div align="center">
<sub>Figura 24 - Modelagem da tabela atividade</sub><br>
<img src="..\document\assets\banco de dados\atividade.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

8. Tabela local
    - Identificação: id (chave primária).
    - Outras colunas:
      - `unidade` (VARCHAR, 100) – Unidade do local.
      - `andar` (VARCHAR, 100) – Andar do local.
      - `sala` (VARCHAR, 100) – Sala do local.
    - Descrição: Armazena informações sobre os locais onde os eventos acontecem.

<div align="center">
<sub>Figura 25 - Modelagem da tabela local</sub><br>
<img src="..\document\assets\banco de dados\local.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

9. Tabela `evento`
    - Identificação: id (chave primária).
    - Chaves estrangeiras:
      - `id_professor` referenciando o ID da tabela `usuario` que tem titulo professor.
      - `id_atividade` referenciando o ID da tabela `atividade`.
      - `id_local` referenciando o ID da tabela `local`.
    - Outras colunas:
      - `data_evento` (DATE) – Data do evento.
      - `hora_inicio` (TIME) – Hora de início do evento.
      - `hora_fim` (TIME) – Hora de fim do evento.
      - `evento_interno` (BINARY) – Indica se o evento é interno.
    - Descrição: Registra os eventos realizados, associando-os a locais, atividades e professores.

<div align="center">
<sub>Figura 26 - Modelagem da tabela evento</sub><br>
<img src="..\document\assets\banco de dados\evento.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

10. Tabela `usuario_atividade`
    - Identificação: id (chave primária).
    - Chaves estrangeiras:
      - `id_usuario` referenciando o ID da tabela `usuario`.
      - `id_atividades` referenciando o ID da tabela `atividade`.
    - Descrição: Relaciona os usuários com as atividades que participam.

<div align="center">
<sub>Figura 27 - Modelagem da tabela usuario_atividade</sub><br>
<img src="..\document\assets\banco de dados\usuario_atividade.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

11. Tabela `visita`
    - Identificação: id (chave primária).
    - Chave estrangeira:
      - `id_usuario` referenciando o ID ta tabela `usuario`.
    - Outras colunas:
      - `data_visita` (DATE) – Data da visita.
      - `hora_entrada_visita` (TIME) – Hora de entrada da visita.
      - `hora_saida_visita` (TIME) – Hora de saída da visita.
    - Descrição: Registra os dados das visitas realizadas pelos usuários.

<div align="center">
<sub>Figura 28 - Modelagem da tabela visita</sub><br>
<img src="..\document\assets\banco de dados\visita.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

12. Tabela `frequencia`
    - Identificação: id (chave primária).
    - Chave estrangeira:
      - `id_usuario` referenciando id da tabela da tabela `usuario`.
    - Outras colunas:
      - `hora` (TIME) – Horário da frequência registrada.
      - `data` (DATE) – Data da frequência registrada.
      - `liberacao` (BINARY) – Indica se houve liberação de acesso.
    - Descrição: Armazena os dados de frequência dos usuários.

<div align="center">
<sub>Figura 29 - Modelagem da tabela frequencia</sub><br>
<img src="..\document\assets\banco de dados\frequencia.png" width="60%" ><br>
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

**Explicações Adicionais** <br>
1. Relações <br>
    - As tabelas no banco de dados foram estruturadas para permitir uma conexão lógica entre as informações de diferentes aspectos do sistema. Seguem as principais relações: 

        - A tabela `usuario` serve como a base para várias outras tabelas, sendo referenciada por `acesso_usuario`, `frequencia`, `visita`, `evento` e `usuario_atividade` através da coluna id. 
        - A tabela `titulo_usuario` é conectada à `tabela usuario` (via `id_titulo_usuario`) e também à tabela `permissao_titulo_usuario`, permitindo que os títulos dos usuários estejam associados às permissões. 
        - A tabela `evento` conecta-se a outras tabelas, como `local` (através de `id_locais`) e `atividade` (através de `id_atividades`), formando um sistema coeso para registrar eventos. 
        - A tabela `permissao_titulo_usuario` relaciona permissões específicas (`permissao`) com os diferentes títulos dos usuários (`titulo_usuario`), criando uma camada de controle de acesso robusta.

2. Chaves Primárias 
   - Cada tabela possui uma chave primária (id), que garante a identificação única de cada registro dentro da tabela. Isso assegura a integridade referencial em todas as operações realizadas no banco de dados.

3. Tipos de Dados
    - O banco de dados foi projetado com atenção aos tipos de dados para garantir eficiência e adequação às necessidades do sistema. Abaixo, detalhamos os tipos de dados utilizados:

        - INTEGER:
            - Utilizado para armazenar números inteiros.
            - Ideal para identificadores únicos, como chaves primárias, e para referências entre tabelas (chaves estrangeiras).
            - Exemplo: id em quase todas as tabelas, e id_usuario em tabelas relacionadas.

        - VARCHAR:
          - Armazena texto de comprimento variável.
          - Usado para nomes, descrições e outros dados textuais.
          - Exemplo: nome na tabela usuario, e tipo_atividade na tabela atividade.

        - CHAR:
          - Um tipo de dado fixo, utilizado em campos de comprimento fixo como CPF.
          - Exemplo: cpf na tabela usuario.

        - DATE:
          - Usado para armazenar datas.
          - Exemplo: data_visita na tabela visita e data_evento na tabela evento.

        - TIME:
          - Representa valores de tempo (hora, minuto e segundo).
          - Exemplo: hora_entrada_visita na tabela visita e hora_inicio na tabela evento.

        - BINARY:
          - Utilizado para valores booleanos (sim ou não).
          - Exemplo: liberacao na tabela frequencia e evento_interno na tabela evento.

&nbsp;&nbsp;&nbsp;&nbsp;A modelagem relacional é uma ferramenta poderosa para a organização e gestão de dados em sistemas de banco de dados. No nosso projeto, ela foi aplicada para criar um modelo de dados eficiente e escalável que atende às necessidades de gerenciar informações sobre a presença dos usuários. Através da definição clara de tabelas e relações, conseguimos garantir a integridade dos dados, facilitar consultas e manter a escalabilidade do sistema. A modelagem relacional, portanto, é essencial para o desenvolvimento de sistemas de banco de dados robustos e eficientes.

### 3.3.4. Arquitetura do Protótipo	<a id="c3-3-4"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, apresentamos a arquitetura do protótipo físico desenvolvida. Esta arquitetura detalha os componentes de hardware e suas conexões, mostrando como eles interagem para garantir o controle de acesso e monitoramento de presença. Também destacamos as tecnologias aplicadas em cada parte do sistema e como essas escolhas foram fundamentais para alcançar uma solução escalável e de fácil manutenção. Para facilitar a compreensão, disponibilizamos um vídeo explicativo sobre a arquitetura do protótipo físico: [Vídeo com a explicação da arquitetura](https://youtu.be/W88Z-ZKSRRs)

&nbsp;&nbsp;&nbsp;&nbsp;Para o desenvolvimento do projeto RedLock, uma gama de tecnologias foram utilizadas em cada área do projeto. A seguir, é possível entender em detalhes cada tecnologia utilizada, como ela foi aplicada e em qual contexto ela se aplica:

- **Protótipo físico**: Utilizou-se a linguagem de programação C++ e o framework Arduino para programar e controlar os componentes do protótipo físico, como sensores, atuadores e microcontroladores, garantindo a operação do sistema.

- **Broker MQTT**: Foi utilizado o HiveMQ para administrar e hospedar o Broker MQTT, permitindo a comunicação entre o protótipo físico e o back-end por meio do protocolo MQTT.

- **Back-end**: Desenvolvido em Python com o framework Flask, o back-end implementa a API que processa as informações do sistema. Além disso, utilizou-se o PostgreSQL como banco de dados, com scripts SQL para criação e manipulação dos dados.

- **Front-end**: Implementado utilizando a linguagem JavaScript com os frameworks React e Streamlit, o front-end fornece uma interface interativa, incluindo o dashboard e o painel de controle para os usuários.

- **Hospedagem e deploy**: O serviço Render foi utilizado para hospedar o front-end (dashboard e painel de controle) e o back-end (API e banco de dados), garantindo a disponibilidade e acessibilidade do sistema.

&nbsp;&nbsp;&nbsp;&nbsp;As tecnologias utilizadas no RedLock foram estudadas e escolhidas a dedo, visando a utilização de tecnologias amplamente presentes no mercado, de alta escalabilidade e fácil manutenção. Desde o uso de C++ e Arduino no protótipo físico até a aplicação de HiveMQ para comunicação MQTT, Python e Flask no back-end, PostgreSQL para o banco de dados, e React no front-end, cada ferramenta foi escolhida estrategicamente para atender às necessidades do projeto. A utilização do serviço Render para hospedagem e deploy reforça a escalabilidade e acessibilidade do sistema, destacando o uso consciente e eficiente das tecnologias disponíveis. A arquitetura modular permite a atualização e manutenção independentes dos módulos, assegurando escalabilidade e adaptabilidade a diferentes cenários.

&nbsp;&nbsp;&nbsp;&nbsp;A arquitetura foi dividida em dois protótipos físicos: o de cadastro e o de reconhecimento. Como cada um terá um microcontrolador dedicado a sua função, é necessário distingui-los na arquitetura, já que serão diferentes. Por isso a necessidade de separá-los na arquitetura do prótotipo.

&nbsp;&nbsp;&nbsp;&nbsp;A arquitetura foi dividida em quatro imagens para entendimento visual claro do diagrama completo: um para o protótipo físico dedicado ao cadastro de digitais e tokens RFID, outro para o protótipo físico dedicado ao reconhecimento de digitais e tokens RFID, um para o back-end e a API do protótipo, e o último é a junção dos três, que é a arquitetura completa do protótipo físico, o diagrama completo.

<div align="center">
  <p>Figura 30 - Arquitetura do Protótipo Reconhecimento</p>
  <img src="..\document\assets\arquitetura\prototipo_fisico_arq_imagem_1.png" alt="fluxo do rastreamento" tyle="max-width: 720px;">
  <sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>
<div align="center">
  <p>Figura 31 - Arquitetura do Protótipo Cadastro</p>
  <img src="..\document\assets\arquitetura\prototipo_fisico_arq_imagem_2.png" alt="fluxo do rastreamento" tyle="max-width: 720px;">
  <sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>
<div align="center">
  <p>Figura 32 - Arquitetura do Protótipo Software</p>
  <img src="..\document\assets\arquitetura\prototipo_fisico_arq_imagem_3.png" alt="fluxo do rastreamento" tyle="max-width: 720px;">
  <sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>
<div align="center">
  <p>Figura 33 - Arquitetura do Protótipo Inteira</p>
  <img src="..\document\assets\arquitetura\prototipo_arquitetura_inteira.png" alt="fluxo do rastreamento" tyle="max-width: 720px;">
  <sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>
<br>

&nbsp;&nbsp;&nbsp;&nbsp;Após a fase de desenvolvimento e concepção do protótipo, foi possível definir os componentes para a implementação do sistema de reconhecimento.

<div align="center">
<sub>Quadro 8 - Protótipo Físico Reconhecimento </sub>
</div>

| **Componente** | **Descrição** | **Tipo** | 
|----------|----------|----------|
| ESP32 | Microcontrolador que opera os módulos do sistema | Microcontrolador ESP32 DevKitC WROOM-32 |  
| Sensor RFID | Leitor RFID utilizado para identificar as TAGs dos alunos | Módulo Sensor RFID RC522 |  
| TAG RFID | TAGs RFID utilizadas para identificação única dos alunos | Tag RFID 13,56MHz ISO14443A |  
| Leitor Biométrico | Sensor que realiza a leitura da impressão digital para autenticação | Sensor Leitor Biométrico DY50 |  
| Display LCD | Exibe mensagens e confirmações sobre o status do sistema | Display LCD 16x2 Serial + Módulo I2C |  
| Fechadura | Controle eletrônico de travamento da catraca | Mini Trava Fechadura Solenoide Eletrônica 12V |  
| LED RGB | Fornece feedback visual do status do sistema | LED RGB 5mm |
| RELÉ| Permite a abertura e fechamento do circuito elétrico da fechadura | Relé 5V de eletromecânico |
| Buzzer| Emite som para sinalizar/confirmar os status do sistema |  Buzzer Zumbador Passivo 5V 85dBA 12x10mm 2400Hz |

<div align='center'>
  <sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<br>

&nbsp;&nbsp;&nbsp;&nbsp;Para garantir o correto funcionamento do protótipo físico, foram estabelecidas as conexões entre os componentes de entrada e saída e os respectivos pinos do ESP32.

<div align="center">
<sub>Quadro 9 - Conexões diagrama do Sensor </sub>
</div>

| **Componente de saída**      | **Pino saída** | **Pino entrada** | **Componente de entrada** |
|------------------------------|----------------|-------------------|---------------------------|
| Sensor RFID                 | 3.3V           | 3.3V             | ESP32                     |
| Sensor RFID                 | RST            | Pino D0          | ESP32                     |
| Sensor RFID                 | GND            | GND              | ESP32                     |
| Sensor RFID                 | MISO           | Pino 19          | ESP32                     |
| Sensor RFID                 | MOSI           | Pino 23          | ESP32                     |
| Sensor RFID                 | SCK            | Pino 18          | ESP32                     |
| Sensor RFID                 | SDA            | Pino 5           | ESP32                     |
| LED RGB (vermelho)          | Positivo       | Pino 33          | ESP32                     |
| LED RGB (verde)             | Positivo       | Pino 32          | ESP32                     |
| LED RGB (negativo)          | Negativo       | GND              | ESP32                     |
| LED RGB (azul)              | Positivo       | Pino 35          | ESP32                     |
| Display I2C                 | GND            | GND              | ESP32                     |
| Display I2C                 | VCC            | 5V               | ESP32                     |
| Display I2C                 | SDA            | Pino 21          | ESP32                     |
| Display I2C                 | SCL            | Pino 22          | ESP32                     |
| Sensor Biométrico DY50      | 3.3V           | 5V               | ESP32                     |
| Sensor Biométrico DY50      | GND            | GND              | ESP32                     |
| Sensor Biométrico DY50      | TX             | Pino 16          | ESP32                     |
| Sensor Biométrico DY50      | RX             | Pino 17          | ESP32                     |
| Buzzer                      | Positivo       | Pino 25          | ESP32                     |
| Buzzer                      | Negativo       | GND              | ESP32                     |

<div align="center">
<sub>Fonte: Material produzido pelo grupo Exodia (2024)</sub>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta etapa do desenvolvimento, os componentes necessários para realizar o processo de cadastro dos usuários foram definidos.

<div align="center">
<sub>Quadro 10 - Protótipo Físico Cadastro </sub>
</div>

| **Componente** | **Descrição** | **Tipo** | 
|----------|----------|----------|
| ESP32 | Microcontrolador que opera os módulos do sistema | Microcontrolador ESP32 DevKitC WROOM-32 |  
| Sensor RFID | Leitor RFID utilizado para identificar as TAGs dos alunos | Módulo Sensor RFID RC522 |  
| TAG RFID | TAGs RFID utilizadas para identificação única dos alunos | Tag RFID 13,56MHz ISO14443A |  
| Leitor Biométrico | Sensor que realiza a leitura da impressão digital para autenticação | Sensor Leitor Biométrico DY50 |  
| Display LCD | Exibe mensagens e confirmações sobre o status do sistema | Display LCD 16x2 Serial + Módulo I2C |  
| LED RGB | Fornece feedback visual do status do sistema | LED RGB 5mm |
| Buzzer| Emite som para sinalizar/confirmar os status do sistema |  Buzzer Zumbador Passivo 5V 85dBA 12x10mm 2400Hz |

<div align="center">
<sub>Fonte: Material produzido pelo grupo Exodia (2024)</sub>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Para a correta implementação do protótipo físico de cadastro, as conexões entre os componentes e o ESP32 foram estabelecidas conforme a tabela abaixo.

<div align="center">
<sub>Quadro 11 - Conexões dos Componentes </sub>
</div>

| **Componente**                 | **Pino saída** | **Pino entrada** | **Descrição**                    |
|--------------------------------|----------------|------------------|----------------------------------|
| Sensor RFID                    | 3.3V           | 3.3V            | Alimentação                     |
| Sensor RFID                    | RST            | Pino D0         | Reset                            |
| Sensor RFID                    | GND            | GND             | Terra                            |
| Sensor RFID                    | MISO           | Pino 19         | Comunicação SPI                  |
| Sensor RFID                    | MOSI           | Pino 23         | Comunicação SPI                  |
| Sensor RFID                    | SCK            | Pino 18         | Comunicação SPI                  |
| Sensor RFID                    | SDA            | Pino 5          | Comunicação I2C                  |
| Sensor Biométrico DY50         | 3.3V           | 5V              | Alimentação                     |
| Sensor Biométrico DY50         | GND            | GND             | Terra                            |
| Sensor Biométrico DY50         | TX             | Pino 16         | Transmissão de dados             |
| Sensor Biométrico DY50         | RX             | Pino 17         | Recepção de dados                |
| Buzzer                         | Positivo       | Pino 25         | Emissão de som                   |
| Buzzer                         | Negativo       | GND             | Terra                            |
| Display I2C                    | GND            | GND             | Terra                            |
| Display I2C                    | VCC            | 5V              | Alimentação                     |
| Display I2C                    | SDA            | Pino 21         | Comunicação I2C                  |
| Display I2C                    | SCL            | Pino 22         | Comunicação I2C                  |

<div align="center">
<sub>Fonte: Material produzido pelo grupo Exodia (2024)</sub>
</div>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;Após essa seção, é possível compreender que a arquitetura do protótipo físico, aliada ao back-end e ao front-end, compõe uma solução integrada importante. A separação em módulos facilita a manutenção e atualização dos componentes, garantindo escalabilidade e adaptabilidade em diferentes ambientes.

### 3.3.5. Arquitetura Refinada da Solução <a id="c3-3-5"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, será apresentada a revisão da arquitetura técnica da solução RedLock, demonstrando como ela suporta os requisitos funcionais e não funcionais definidos. A arquitetura foi refinada com ajustes para otimizar o fluxo de dados, garantir melhor desempenho, segurança e usabilidade, bem como assegurar escalabilidade e manutenção simplificada.

&nbsp;&nbsp;&nbsp;&nbsp;A revisão da arquitetura é detalhada com base em quatro partes principais:

- **Protótipo Físico de Reconhecimento**
- **Protótipo Físico de Cadastro**
- **Back-End**
- **Front-End**

&nbsp;&nbsp;&nbsp;&nbsp;Cada componente da arquitetura foi projetado para interagir de forma integrada, possibilitando um sistema robusto para controle de acesso e monitoramento de presença no Instituto Apontar.

#### Protótipo Físico de Reconhecimento

&nbsp;&nbsp;&nbsp;&nbsp;O protótipo de reconhecimento é responsável pela identificação de usuários já cadastrados. Ele utiliza sensores biométricos e RFID para validar o acesso em tempo real. Os principais componentes são:

- **Token RFID**: Identifica usuários através de tags ou cartões RFID.
- **Sensor RFID RC522**: Captura os dados dos tokens RFID e os envia para o ESP32.
- **Sensor Biométrico DY50**: Lê e valida as impressões digitais.
- **Microcontrolador ESP32**: Processa os dados dos sensores, controla a trava eletrônica e envia informações ao MQTT Broker.
- **Display LCD**: Exibe mensagens informativas sobre o status da identificação.
- **LED RGB**: Fornece feedback visual (verde para acesso liberado, vermelho para negado).
- **Buzzer**: Emite sinais sonoros para feedback durante o reconhecimento.
- **Relé e Trava Eletrônica**: Controlam a liberação ou bloqueio de acesso.

**Ajustes Realizados:**

- Integração aprimorada entre ESP32 e MQTT Broker para sincronização de dados em tempo real.
- Otimização do tempo de resposta para garantir autenticação em menos de 3 segundos (RNF01).

### Protótipo Físico de Cadastro

&nbsp;&nbsp;&nbsp;&nbsp;Este protótipo é dedicado ao cadastro de novos usuários. Ele utiliza os mesmos sensores, mas com foco em armazenar dados biométricos e RFID no banco de dados. Os componentes principais incluem:

- **Sensor RFID RC522**: Captura o código dos tokens RFID.
- **Sensor Biométrico DY50**: Captura e armazena as impressões digitais dos usuários.
- **ESP32**: Processa os dados e envia para o MQTT Broker e a API.
- **Display LCD**: Informa o status do cadastro.
- **LED RGB e Buzzer**: Indicam sucesso ou falha no processo de cadastro.

**Ajustes Realizados:**

- Implementação de criptografia de dados biométricos durante a transmissão (RNF05).
- Melhorias na interface de feedback para informar claramente o status do cadastro (RF01).

### Back-End

&nbsp;&nbsp;&nbsp;&nbsp;O back-end consiste em uma*API Flask e um banco de dados PostgreSQL. Ele é responsável por registrar, processar e armazenar os dados enviados pelos protótipos. Os componentes são:

- **API/Servidor**: Processa os dados de leitura e cadastro dos protótipos.
- **Banco de Dados**: Armazena informações de usuários, logs de acesso e dados biométricos.
- **MQTT Broker (HiveMQ)**: Facilita a comunicação entre os protótipos e a API em tempo real.

**Ajustes Realizados:**

- Implementação de armazenamento offline e sincronização automática (RF06).
- Melhorias de segurança com criptografia HTTPS e armazenamento seguro dos dados biométricos (RNF05).

### Front-End

&nbsp;&nbsp;&nbsp;&nbsp;O front-end é a interface do sistema, o painel de controle, desenvolvida em React. Ele inclui:

- **Dashboard**: Exibe gráficos e estatísticas sobre a frequência de alunos e colaboradores (RF04).
- **Plataforma de Controle**: Permite o cadastro de novos usuários e a gestão de permissões (RF05).

**Ajustes Realizados:**

- Melhorias na visualização em tempo real dos dados sincronizados pelo **MQTT Broker** (RNF02).
- Implementação de filtros dinâmicos e gráficos interativos para facilitar a consulta de dados.

### Justificativa da Arquitetura

&nbsp;&nbsp;&nbsp;&nbsp;A arquitetura refinada atende aos requisitos funcionais e não funcionais da seguinte forma:

| **ID** | **Funcional?** | **Descrição do Requisito**                        | **Como a Arquitetura Aborda**                                             |
| ------ | -------------- | ------------------------------------------------- | ------------------------------------------------------------------------- |
| RF01   | Sim            | Cadastro de novos usuários (digitais e RFID).     | API e ESP32 integrados ao sensor biométrico e RFID para cadastro.         |
| RF02   | Sim            | Controle de abertura/fechamento da catraca.       | ESP32 controla o relé e trava eletrônica com base nos dados dos sensores. |
| RF03   | Sim            | Registro de entrada e saída dos usuários.         | Dados enviados pelo ESP32 para a API e armazenados no banco de dados.     |
| RF04   | Sim            | Interface com gráficos e filtros de presença.     | Dashboard em React exibe dados processados pela API.                      |
| RF05   | Sim            | Sistema de cadastro com controle de acesso.       | Plataforma de controle com autenticação integrada à API.                  |
| RF06   | Sim            | Armazenamento offline e sincronização automática. | ESP32 armazena dados temporários e sincroniza via MQTT.                   |
| RNF01  | Não            | Autenticação em menos de 3 segundos.              | Processamento rápido local com ESP32.                                     |
| RNF02  | Não            | Atualização em tempo real.                        | MQTT Broker facilita comunicação instantânea entre componentes.           |
| RNF05  | Não            | Criptografia de dados biométricos.                | Transmissão segura via MQTT e HTTPS.                                      |

### Conclusão

&nbsp;&nbsp;&nbsp;&nbsp;A arquitetura refinada da solução **RedLock** integra eficientemente os componentes de hardware e software para oferecer uma solução robusta de controle de acesso e monitoramento de presença. A modularidade e a integração entre protótipos físicos, back-end e front-end garantem escalabilidade, segurança e facilidade de manutenção, atendendo plenamente aos requisitos funcionais e não funcionais estabelecidos.

## 3.4. Resultados <a id="c3-4"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, apresentamos os resultados obtidos durante o desenvolvimento e implementação do projeto. A validação foi realizada por meio de protótipos desenvolvidos tanto em ambiente simulado quanto em ambiente físico, abordando diferentes fases do processo. Os testes incluem simulações virtuais utilizando o Wokwi, a construção de um protótipo físico offline e online, e a integração com protocolos de comunicação como MQTT e I2C.  

&nbsp;&nbsp;&nbsp;&nbsp;As subseções detalham cada etapa dos testes, com foco nos cenários de uso, funcionamento dos componentes, e análise dos resultados obtidos. Também são apresentados os problemas detectados e as melhorias sugeridas com base nos testes de usabilidade, assegurando que a solução final atenda às necessidades e requisitos identificados.

### 3.4.1. Protótipo Inicial do Projeto usando o Simulador Wokwi <a id="c3-4-1"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O protótipo inicial foi desenvolvido utilizando o simulador Wokwi, uma ferramenta online que permite a simulação de circuitos eletrônicos, especialmente microcontroladores como o ESP32. O Wokwi possibilita a criação de protótipos virtuais de hardware, utilizando a linguagem de programação C++ e a configuração de diversos sensores. No projeto atual, utilizamos o ESP32 em conjunto com botões, LEDs e buzzer para simular o comportamento esperado do sistema.

- **Link para o protótipo inicial do projeto:**
[Protótipo inicial](https://wokwi.com/projects/412651623701154817)

- **Link para o vídeo demonstrativo do protótipo:**
[Vídeo do Protótipo](https://youtu.be/kIvZJPgC-Yk)

#### Descrição do Protótipo

O protótipo simula o funcionamento do sistema utilizando os seguintes componentes:

- Microcontrolador ESP32: Controla a lógica de operação.
- Botões: Para simular a interação do usuário (cadastro, leitura biométrica e RFID).
- LEDs: Indicadores visuais para diferentes estados e resultados das leituras.
- Buzzer: Emite sons para sinalizar sucesso ou falha nas operações.
- Slide Switch: Altera entre os modos de operação (Biometria e RFID).

&nbsp;&nbsp;&nbsp;&nbsp;A tabela exemplifica casos de sucesso e falhas, simulando o funcionamento do sistema com ESP32, botões, LEDs e o buzzer. Incluí um exemplo para cada cenário relevante do código, tanto para leituras de biometria quanto para o RFID.

<div align="center">
<sub>Quadro 12 - Relatório de testes </sub>
</div>

| #  | Bloco      | Componente de entrada  | Leitura da entrada   | Componente de saída | Leitura da saída        | Descrição                                                                 |
|----|------------|------------------------|----------------------|---------------------|-------------------------|---------------------------------------------------------------------------|
| 01 | Biometria  | Botão verde             | Pressionado (LOW)    | LED vermelho        | Aceso por 1s            | Cadastro de biometria falhou. LED vermelho acende e buzzer emite som grave. |
| 02 | Biometria  | Botão verde             | Pressionado (LOW)    | LED verde           | Aceso por 1s            | Biometria lida com sucesso. LED verde acende e buzzer emite som agudo.     |
| 03 | RFID       | Botão azul (switch)     | Alternado            | LED azul            | Aceso por 1s            | Alternância entre modo de leitura e cadastro de cartões. LED azul indica a troca. |
| 04 | RFID       | Botão vermelho          | Pressionado (LOW)    | LED vermelho        | Aceso por 1s            | Falha ao registrar cartão RFID. LED vermelho acende e buzzer emite som grave. |
| 05 | Biometria  | Slide switch            | Posicionado em HIGH  | Nenhum              | Nenhum                  | O sistema está no modo RFID. Sem ação de leitura de biometria.              |
| 06 | Biometria  | Slide switch            | Posicionado em LOW   | LED azul            | Aceso por 1s            | O sistema está no modo Biometria. Função de cadastro ou leitura biométrica ativa. |
| 07 | Geral      | Tempo                  | 1s                   | LEDs                | Todos apagados          | Todos os LEDs desligam automaticamente após 1 segundo, caso acesos.        |

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

Descrição dos testes:
1. Cadastro de biometria com falha (linha 1): Ao pressionar o botão verde, o sistema tenta registrar uma biometria, mas a operação falha. O LED vermelho acende, e o buzzer emite um som grave.
2. Leitura de biometria com sucesso (linha 2): O botão verde é pressionado e a leitura da biometria ocorre com sucesso, acendendo o LED verde e emitindo um som agudo.
3. Alternância entre modos (linha 3): Ao alternar o switch, o sistema troca entre os modos de leitura/cadastro de biometria e RFID, e o LED azul indica a mudança.
4. Falha no registro de RFID (linha 4): O botão vermelho é pressionado durante o registro de um cartão RFID, mas o registro falha, acendendo o LED vermelho e emitindo um som grave.
5. Leitura de modo ativo (linha 5): Quando o switch está na posição HIGH, o sistema está no modo RFID e não realiza nenhuma leitura de biometria.
6. Entrada de modo biometria (linha 6): O switch na posição LOW indica que o sistema está no modo de leitura/cadastro de biometria. O LED azul acende para confirmar o modo.
7. Desligamento automático de LEDs (linha 7): Após 1 segundo, qualquer LED aceso será desligado automaticamente para economizar energia.

Funções `setup()` e `loop()`:

&nbsp;&nbsp;&nbsp;&nbsp;O código contém as funções `setup()` e `loop()`. A função `setup()` é usada para configurar os pinos do microcontrolador, como entradas (botões) ou saídas (LEDs e buzzer), além de inicializar a comunicação Serial. Ela é executada apenas uma vez no início da execução. Já a função `loop()` executa continuamente durante o funcionamento do sistema, verificando o estado dos botões e atualizando a lógica de controle dos LEDs e do buzzer conforme as interações do usuário. Assim, o sistema responde de forma eficiente a cada ação, como pressionar um botão ou alternar um switch.

Declaração de funções adicionais:

&nbsp;&nbsp;&nbsp;&nbsp;O código também inclui funções auxiliares que melhoram a organização e a reutilização de código. Essas funções são chamadas de `setup()` e `loop()` para modularizar o comportamento do sistema. Exemplos incluem:
- `desligarLedsAutomaticamente()`: Esta função garante que todos os LEDs sejam apagados automaticamente após um período de inatividade, economizando energia.
- `ligarLed()`: Função utilizada para acender o LED correspondente ao estado atual, seja uma falha de leitura de biometria, sucesso na leitura, ou alternância de modo.
- `trocarFuncao()`: Garante a alternância entre as funções do sistema, como o modo de leitura/cadastro de biometria e RFID.

Definição de classes:

&nbsp;&nbsp;&nbsp;&nbsp;Para estruturar melhor o código, foram implementadas duas classes principais: `Biometrics` e `RFID`. Essas classes encapsulam as funcionalidades relacionadas à biometria e RFID, respectivamente, tornando o código mais simples de entender. No `loop()`, instâncias dessas classes, chamadas `biometrics` e `rfid`, são utilizadas para chamar métodos específicos como `registrarBiometria()`, `lerBiometria()`, `registrarCartao()`, e `lerCartao()`. Essa abordagem facilita a adição de novos métodos ou a modificação de funcionalidades sem impactar o restante do sistema.

&nbsp;&nbsp;&nbsp;&nbsp;Estamos satisfeitos com o que conseguimos realizar na primeira sprint do projeto, alcançando uma implementação funcional e atendendo aos requisitos propostos. No entanto, já estamos trabalhando em cima dos pontos de melhoria identificados para otimizar ainda mais a solução. Nosso objetivo é, ao longo das próximas sprints, aprimorar continuamente o protótipo e entregar uma solução em seu maior potencial, atendendo às expectativas e necessidades dos nossos parceiros do instituto.

### 3.4.2. Protótipo Físico do Projeto (offline) 	<a id="c3-4-2"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Casos de teste são fundamentais para a validação de qualquer sistema, seja ele digital, físico ou uma combinação de ambos, como no caso de um protótipo IoT com leitura biométrica. Eles consistem em um conjunto de cenários planejados para avaliar e documentar o comportamento da solução, buscando garantir que todos os requisitos funcionais e não funcionais sejam atendidos. Cada caso de teste descreve uma situação específica, incluindo o estado inicial do sistema, as ações realizadas pelo usuário e o resultado esperado.

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, apresentaremos o desenvolvimento do protótipo físico do projeto. O objetivo é detalhar as situações de teste realizadas com o protótipo offline, evidenciando os cenários de uso, incluindo tanto os casos de sucesso quanto aqueles que demonstram possíveis falhas.

<div align="center">
<sub>Figura 34 - Protótipo físico da solução - circuito</sub>
<img src="..\document\assets\business\protótipo físico.jpeg" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Na imagem, é ilustrado o processo de identificação de alunos ou funcionários utilizando a biometria. Para que o reconhecimento ocorra, o usuário precisa apenas encostar seu dedo no sensor, que realiza a leitura das informações armazenadas. Após a leitura bem-sucedida, os dados são exibidos no display, permitindo uma visualização da identificação realizada.

&nbsp;&nbsp;&nbsp;&nbsp;Após a identificação dos requisitos, foi iniciado uma série de testes para validar a eficácia de nosso protótipo IoT baseado na biometria digital. O propósito desses testes foi validar o funcionamento correto do sistema e identificar particularidades no desempenho em diferentes situações. Cada teste foi projetado com a intenção de explorar e documentar os potenciais usos da solução. Veja os testes a seguir no quadro:

<br>
<div align="center">
<sub>Quadro 13 - Casos de Testes do Protótipo Físico do Projeto (offline) </sub>
</div>

| **#** | **Descrição**                                | **Pré-condição**                        | **Procedimento de teste**                          | **Pós-condição/Resultado esperado**                     | **Observações**                    |
|-------|----------------------------------------------|-----------------------------------------|----------------------------------------------------|---------------------------------------------------------|-----------------------------------|
| 01    | Cadastro de biometria bem-sucedido           | Dispositivo ligado, usuário cadastrado  | Posicione o dedo no sensor para o cadastro         | Biometria cadastrada com sucesso e confirmação no monitor | Utilize um dedo diferente para teste |
| 02    | Falha no cadastro de biometria               | Dispositivo ligado, usuário cadastrado  | Posicione o dedo de forma incorreta no sensor      | Mensagem de erro no display, solicitando nova tentativa   | Testar com dedo sujo ou uma posição diferente do padrão     |
| 03    | Leitura de biometria bem-sucedida            | Dispositivo ligado, biometria cadastrada | Posicione o dedo no sensor para leitura            | Autenticação bem-sucedida, acesso permitido              | Utilize o dedo cadastrado         |
| 04    | Falha na leitura de biometria                | Dispositivo ligado, biometria cadastrada | Posicione um dedo não cadastrado no sensor         | Autenticação falhou, acesso negado                        | Utilize um dedo não cadastrado    |


<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Os testes realizados confirmam um desempenho satisfatório do protótipo inicial. A leitura da biometria e a resposta a entradas não cadastradas evidenciam uma funcionalidade importante do sistema. Esses resultados positivos indicam uma capacidade de atender às demandas identificadas, proporcionando uma base para aprimoramentos e futuros desenvolvimentos.

### 3.4.3. Protótipo do Projeto com MQTT e I2C	<a id="c3-4-3"></a>

&nbsp;&nbsp;&nbsp;&nbsp; Um protocolo de comunicação da internet é um conjunto de regras que define como os dados são trocados entre dispositivos na rede. Ele garante a comunicação eficiente e segura entre sistemas diferentes. Em vista disso, na solução Red Lock foram usados dois principais protocolos, o MQTT e o I2C, que se mostraram essenciais para o funcionamento da mesma.

&nbsp;&nbsp;&nbsp;&nbsp; Usado em comumente em diversos dispositivos e soluções IoT, o MQTT (Message Queuing Telemetry Transport) , assim como o HTTP (Hypertext Transfer Protocol), é um protocolo de comunicação entre dois ou mais clientes. Em uma comunicação MQTT, existem três principais atuantes, o Publisher, Subscriber e o Broker, cada um deles desempenha uma função fundamental no funcionamento das soluções. O Broker (servidor MQTT) funciona como um blog da internet, se conecta aos clientes a partir do protocolo e possui tópicos. Ainda em um cenário de blog, as pessoas que publicam mensagens(payload) são os Publishers, e as que se inscrevem nos tópicos para conseguir ver as mensagens, são os Subscribers. Dessa forma, os dispositivos conseguem sempre enviar informações, e os outros atuantes da solução, como uma aplicação, podem sempre “escutar” esses dados.

&nbsp;&nbsp;&nbsp;&nbsp;Nessa perspectiva, no panorama do projeto, o protocolo MQTT, operando no modelo de inscrição e subscrição, seria a ponte entre o ESP32 e a aplicação, levando os dados recolhidos no sensor biométrico e leitor RFID, a API na aplicação Flask e permitindo a visualização em tempo real desses dados na Dashboard.

&nbsp;&nbsp;&nbsp;&nbsp;A comunicação I2C (Inter-Integrated Circuit) é um protocolo que permite a conexão de múltiplos dispositivos em um mesmo barramento de dados, utilizando apenas dois fios: um para o relógio (SCL) e outro para os dados (SDA). Esse protocolo é amplamente utilizado em soluções que requerem comunicação eficiente e simplificada entre microcontroladores e periféricos.

&nbsp;&nbsp;&nbsp;&nbsp;No projeto Red Lock, o protocolo I2C foi aplicado exclusivamente no display LCD, permitindo que o ESP32 envie comandos e dados para exibição de informações relevantes, como mensagens de status ou resultados de autenticação. Essa integração simplificada garante uma comunicação eficiente e ocupa poucos pinos no microcontrolador, otimizando o uso do hardware.


&nbsp;&nbsp;&nbsp;&nbsp;O quadro a seguir apresenta registros de várias situações de uso do sistema, abordando diferentes cenários para validar o funcionamento do protótipo desenvolvido. Os testes contemplam interações com cartões RFID, leitores biométricos, integração via MQTT e exibição de dados em displays LCD conectados por I2C. Esses registros buscam cobrir as necessidades operacionais e as especificações do projeto, assegurando um sistema intuitivo e funcional.

<div align="center">
<sub>Quadro 14 - Testes de Protótipo com MQTT e I2C </sub>
</div>

| **#** | **Configuração do Ambiente**                                         | **Ação do Usuário**                                               | **Resposta Esperada do Sistema**                                                                                     | **Resposta Recebida do Sistema**                                                                                     |
|-------|----------------------------------------------------------------------|--------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|
| 01    | ESP32 configurada com MQTT para conexão com a nuvem e display LCD via I2C. | Aproximação de um cartão RFID autorizado.                          | O monitor serial exibe o ID correspondente do cartão autorizado e o display LCD mostra os dados da tag.              | Caso de sucesso: Dados exibidos corretamente no serial e LCD. Caso de falha: Monitor exibe "Erro na leitura".        |
| 02    | Configuração igual ao caso anterior, mas com tag RFID não cadastrada. | Aproximação de um cartão RFID não cadastrado.                      | O monitor serial exibe que o cartão não está cadastrado e sugere opções para registro. LCD exibe "Sem dados".         | Caso de sucesso: Mensagem de erro exibida corretamente. Caso de falha: Monitor não reconhece a tag e não exibe opções.|
| 03    | ESP32 integrada ao dashboard via MQTT e display LCD ativo.           | Acesso à interface do dashboard para verificar dados coletados.    | A tabela do dashboard exibe os valores coletados pela ESP32 para visualização e gerenciamento.                       | Caso de sucesso: Dados exibidos corretamente no dashboard. Caso de falha: Tabela não exibe dados coletados.          |
| 04    | Sistema em execução, cartão RFID válido previamente cadastrado.      | Aproximação de um cartão RFID autorizado.                          | Monitor serial exibe ID do cartão, envia os dados para o dashboard e LCD exibe informações da tag.                    | Caso de sucesso: Dados exibidos e enviados corretamente. Caso de falha: Monitor exibe mensagem de erro.              |
| 05    | ESP32 inicializada sem nenhum cartão próximo ao leitor.              | Nenhuma interação do usuário.                                      | Monitor serial exibe "Aproxime a tag" e LCD mostra "Aproxime a tag".                                                 | Caso de sucesso: Mensagem exibida corretamente. Caso de falha: LCD não exibe mensagem ou monitor apresenta erro.      |
| 06    | Tag RFID válida e cadastrada, mas com falha de conexão Wi-Fi.        | Aproximação de um cartão RFID autorizado.                          | Monitor serial exibe "Erro na conexão Wi-Fi" e tenta reconectar. Dados não enviados ao dashboard.                     | Caso de sucesso: Mensagem de erro exibida corretamente. Caso de falha: Sistema permanece em loop sem feedback.       |
| 07    | Configuração funcional com um cartão RFID com dados vazios.          | Aproximação de um cartão com dados vazios.                         | Monitor serial exibe "Dados vazios na tag" e sugere opções de gravação. LCD exibe "Sem dados".                        | Caso de sucesso: Mensagem e opções exibidas corretamente. Caso de falha: Monitor não reconhece o cartão.             |
| 08    | Sistema em execução, leitor biométrico configurado.                  | Leitura da digital de um usuário previamente cadastrado.           | ESP32 valida a digital, LCD exibe "Acesso liberado", publica no MQTT, e o dashboard atualiza os dados.               | Caso de sucesso: Dados registrados e atualizados corretamente. Caso de falha: Monitor exibe "Erro de leitura".       |
| 09    | Configuração funcional com servidor MQTT ativo e leitor biométrico.  | Leitura de digital não cadastrada.                                 | ESP32 exibe "Digital não cadastrada", publica no MQTT a tentativa, e o dashboard exibe alerta de falha.               | Caso de sucesso: Mensagem e alerta exibidos corretamente. Caso de falha: Nenhuma resposta do sistema.                |
| 10    | ESP32 integrada a múltiplos dispositivos distribuídos em salas diferentes. | Movimento de pessoa detectado por um sensor conectado ao ESP32.   | Sensor registra o movimento, envia ID e local da sala para o dashboard. O dashboard atualiza os dados em tempo real.  | Caso de sucesso: Dados exibidos corretamente no dashboard. Caso de falha: Sensor não reconhece o movimento.          |
| 11    | Configuração funcional com ESP32 e dashboard em integração ativa.    | Adição de um novo ESP32 para monitoramento em outra área.          | O dashboard reconhece o novo dispositivo e exibe as informações de detecção da nova área.                            | Caso de sucesso: Novo dispositivo registrado corretamente. Caso de falha: O dashboard não reconhece o novo dispositivo.|
| 12    | Configuração funcional com Wi-Fi instável.                           | Aproximação de uma tag RFID válida.                                | Monitor serial exibe "Erro na conexão Wi-Fi" e tenta reconectar.                                                     | Caso de sucesso: Sistema reconecta ao Wi-Fi e retoma operações. Caso de falha: Sistema não se reconecta.             |
| 13    | Leitor biométrico funcional, banco de dados ativo.                   | Tentativa de registro de digital para um usuário não cadastrado.   | Frontend exibe "Usuário não encontrado no sistema" e impede o registro.                                              | Caso de sucesso: Mensagem exibida corretamente. Caso de falha: Sistema tenta iniciar registro indevidamente.         |
| 14    | Configuração funcional com banco de dados ativo e cadastro completo. | Geração de relatório mensal no dashboard.                         | Sistema gera relatório consolidado em PDF e Excel para download imediato.                                            | Caso de sucesso: Relatório gerado e exibido corretamente. Caso de falha: Relatório não é gerado ou exibe dados errados.|
| 15    | Configuração funcional com display LCD ativo.                        | Operação normal do sistema exibindo mensagens no LCD.              | LCD exibe mensagens correspondentes como "Aproxime a tag" ou informações da tag lida.                                | Caso de sucesso: Mensagens exibidas corretamente. Caso de falha: LCD não exibe mensagens ou apresenta erros.         |

<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Essa tabela combina cenários abrangentes com descrições das respostas esperadas e efetivamente recebidas, cobrindo desde casos de sucesso e potenciais falhas para validação completa do sistema.

&nbsp;&nbsp;&nbsp;&nbsp;Abaixo estão registros visuais que ilustram os Dashboards já desenvolvidos, incluindo o relatório de eventos e o relatório de acessos, além de um teste de envio de mensagens e inscrição no Broker MQTT hospedado na nuvem para o recebimento dessas mensagens.

## Demonstração 1 do Dashboard desenvolvido para o Front-End
<div align="center">
<sub>Figura 35 - Caso de teste - Demonstração do relatório de eventos na Dashboard</sub>
<img src="..\document\assets\testes\dashboard1.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

## Demonstração 2 do Dashboard desenvolvido paro o Front-End
<div align="center">
<sub>Figura 36 - Caso de teste - Demonstração do relatório de acesso na Dashboard</sub>
<img src="..\document\assets\testes\dashboard2.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

## Demonstração visual das publicações feitas pelo ESP32
<div align="center">
<sub>Figura 37 - Caso de testes - Visualização do Serial Monitor do ESP32 realizando o envio das mensagens</sub>
<img src="..\document\assets\testes\mqttEsp.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>


## Demonstração visual da recepção das mensagens enviadas pelo ESP32
<div align="center">
<sub>Figura 38 - Caso de testes - Demonstração de um Web client MQTT inscrito nos tópicos atuantes da solução</sub>
<img src="..\document\assets\testes\mqttCloud.png" width="100%">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;O emprego do Broker em um serviço Cloud, não é apenas uma escolha estratégica, mas um ponto essencial para atender tanto uma manutenção facilitada,, quanto escalabilidade, garantindo uma conectividade global, permitindo inscrição de diferentes clientes em locais adversos do mundo.


&nbsp;&nbsp;&nbsp;&nbsp;A conexão entre esses dois elementos fundamentais, se mostra quando o protocolo I2C facilita a comunicação entre o ESP32 e o display, assim diminuindo a complexidade do hardware e aumentando a eficiência do design. Nesse sentido, ao otimizar o sistema físico, o protocolo I2C “libera” poder computacional para o funcionamento potente do MQTT, maximizando a performance da transferência de dados. O que garantiria a realização de outros processos de forma mais eficaz, tanto no RNF05 em questão de desempenho, quanto em funcionalidades, como o RF03 e RF06, das sessões 3.3.2 de Requisitos não funcionais e 3.3.1 de Requisitos funcionais.

&nbsp;&nbsp;&nbsp;&nbsp;A aplicação sucedida e conjunta dos protocolos I2C e MQTT, fazem com que o projeto realizado pelo grupo Exodia, seja robusto, eficiente e versátil a novas funcionalidades e dispositivos, atendendo as demandas do Instituto Apontar.

### 3.4.4. Protótipo Físico do Projeto (online) <a id="c3-4-4"></a>

&nbsp;&nbsp;&nbsp;&nbsp;O protótipo físico deste projeto integra tecnologias como o microcontrolador ESP32, leitores RFID, sensores biométricos e comunicação via Broker MQTT. Ele foi projetado para gerenciar o controle de acesso de usuários de forma automatizada, com registros armazenados em um banco de dados e visualizados em um painel de controle. O sistema permite operações online e offline, garantindo o registro das tentativas de acesso e oferecendo feedback em tempo real através de um LCD e indicadores visuais, como LEDs e buzzers. Este protótipo visa atender às demandas de controle de acesso em ambientes diversos.

&nbsp;&nbsp;&nbsp;&nbsp;Os casos de teste a seguir foram elaborados para verificar o correto funcionamento do protótipo físico do projeto em diferentes cenários. Cada teste simula situações específicas de uso e descreve a configuração do ambiente, as ações dos usuários e as respostas esperadas do sistema. Eles garantem que os componentes como o ESP32, leitores RFID, sensores biométricos, Broker MQTT, e a dashboard funcionem perfeitamente.

<div align="center">
<sub>Quadro 15 - Testes do Protótipo Físico Online</sub>
</div>

| **#** | **Configuração do Ambiente**                                     | **Ação do Usuário**                                             | **Resposta Esperada do Sistema**                                                                                              | **Resposta Recebida do Sistema**                                                                                               |
|--------|------------------------------------------------------------------|------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| **01** | ESP32 conectado ao leitor RFID, sensor biométrico e LCD.        | Aproximação de um cartão RFID autorizado.                       | LCD exibe "**Acesso liberado**", relé destrava porta e dados são enviados ao dashboard.                                      | Caso de sucesso: Operação executada corretamente. Caso de falha: Mensagem de erro exibida no LCD.                            |
| **02** | Leitor RFID ativo.                                              | Aproximação de um cartão RFID não cadastrado.                   | LCD exibe "**Acesso negado**", e o sistema registra tentativa de acesso inválido no dashboard.                               | Caso de sucesso: Mensagem exibida e tentativa registrada. Caso de falha: Nenhum registro ou mensagem.                        |
| **03** | Sensor biométrico conectado ao ESP32 e internet ativa.          | Leitura de uma digital previamente cadastrada.                  | LCD exibe "**Acesso liberado**", ESP32 registra no banco de dados e dashboard atualiza os dados em tempo real.               | Caso de sucesso: Fluxo completo realizado. Caso de falha: Mensagem "**Erro de leitura**" exibida no LCD.                     |
| **04** | Sistema configurado para fallback em caso de falha de Wi-Fi.    | Aproximação de um cartão RFID válido, mas com Wi-Fi desconectado. | LED indica erro de conexão; dados armazenados localmente para envio posterior.                                               | Caso de sucesso: Dados armazenados localmente. Caso de falha: Sistema trava ou não registra dados.                           |
| **05** | Sistema integrado ao dashboard com conexão ao Broker MQTT.      | Consulta de dados no dashboard após várias interações.          | Dashboard exibe logs de acesso em tempo real, incluindo dados de tentativas válidas e inválidas.                             | Caso de sucesso: Dados exibidos corretamente no dashboard. Caso de falha: Informações desatualizadas ou inconsistentes.      |
| **06** | ESP32 conectado a sensores biométricos e RFID, Broker MQTT ativo. | Aproximação de um cartão RFID não cadastrado.                   | Monitor serial exibe "**Erro de leitura**", e LCD exibe "**Cartão não cadastrado**".                                          | Caso de sucesso: Mensagem de erro exibida corretamente. Caso de falha: Nenhuma mensagem exibida.                             |
| **07** | Leitor biométrico configurado.                                | Tentativa de acesso com digital não cadastrada.                 | LCD exibe "**Digital não cadastrada**".                                                                                      | Caso de sucesso: Mensagem exibida corretamente. Caso de falha: Nenhuma mensagem exibida.                                      |
| **08** | ESP32 conectado à internet.                                   | Tentativa de acesso com digital não cadastrada.                 | Tentativa registrada no banco e alerta exibido na dashboard.                                                                 | Caso de sucesso: Tentativa registrada corretamente. Caso de falha: Tentativa não registrada.                                  |
| **09** | Sistema em operação normal com Wi-Fi estável.                   | Atualização do firmware do ESP32 durante operação.              | Sistema reinicia e retorna à operação normal após a atualização, sem perda de dados.                                         | Caso de sucesso: Firmware atualizado e sistema operacional. Caso de falha: Sistema não reinicia ou reinicia com falhas.      |
| **10** | Conexão com Broker MQTT e sensor biométrico ativo.              | Tentativa de acesso simultânea por dois usuários em catracas diferentes. | ESP32 processa as tentativas em sequência, exibindo mensagens correspondentes no LCD e registrando os acessos no banco.    | Caso de sucesso: Acessos processados corretamente. Caso de falha: Sistema não responde ou apresenta erro em um dos acessos.  |
| **11** | Fallback local configurado para falha de comunicação MQTT.      | Falha na comunicação com o Broker MQTT.                         | Dados armazenados localmente no ESP32, com reenvio automático após reconexão.                                                | Caso de sucesso: Dados reenviados corretamente após reconexão. Caso de falha: Dados perdidos ou não reenviados.              |
| **12** | ESP32 configurado para novos dispositivos.                      | Registro de um novo ESP32 na rede MQTT.                         | Broker MQTT reconhece o novo dispositivo, e dashboard exibe os dados enviados.                                               | Caso de sucesso: Dispositivo registrado corretamente. Caso de falha: Dispositivo não reconhecido pelo broker.                |
| **13** | Banco de dados configurado para gerar relatórios.               | Solicitação de relatório mensal no dashboard.                   | Relatório gerado em PDF e disponibilizado para download.                                                                     | Caso de sucesso: Relatório gerado corretamente. Caso de falha: Erro ao gerar o relatório.                                    |
<div align="center">
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

**Explicação dos Diagramas UML**

&nbsp;&nbsp;&nbsp;&nbsp;Um diagrama de sequência **UML** (Unified Modeling Language) é uma representação visual que descreve como os objetos interagem em uma sequência específica de eventos ao longo do tempo. Ele é especialmente útil para detalhar o comportamento dos sistemas, mostrando o fluxo de mensagens entre os objetos, suas respectivas chamadas de métodos e as respostas recebidas.

&nbsp;&nbsp;&nbsp;&nbsp;Os diagramas a seguir correspondem aos testes descritos na tabela acima:

<div align="center">
<sub>Figura 39 - Diagrama UML - Acesso de um usuário (caso de teste 01)</sub>  <br><br>
<img src="..\document\assets\diagramaUML\acesso.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

- Offline

&nbsp;&nbsp;&nbsp;&nbsp;Com o cartão já cadastrado, o usuário o aproxima do leitor RFID. O leitor identifica o código HASH no cartão e o envia ao ESP32, que verifica se o código está registrado. Caso esteja, o acesso é liberado. O usuário recebe essa confirmação de três formas: uma mensagem no display informando "Acesso liberado", o LED acendendo na cor verde e um som breve e agudo emitido pelo buzzer.

- Online

&nbsp;&nbsp;&nbsp;&nbsp;Quando o modelo está online, o processo de liberação segue o mesmo fluxo. No entanto, agora o sistema também registra a presença. Após verificar o HASH no ESP32, o dispositivo envia as informações de presença do usuário (como horário de entrada e data) via MQTT para uma API, que relaciona essas informações ao usuário correspondente ao HASH e envia para o banco de dados, registrando a presença.


<div align="center">
<sub>Figura 40 - Diagrama UML - Cadastro de um usuário</sub>  <br><br>
<img src="..\document\assets\diagramaUML\cadastro.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Para cadastrar um usuário e associar um cartão RFID a ele, deve-se, primeiramente, acessar a dashboard. Após realizar o login como administrador, será exibida uma opção de cadastro de usuário. Nesta seção, serão apresentados campos para inserir as informações do usuário, que serão enviadas para a API, que registrará no Banco de Dados. Concluída essa etapa, será possível selecionar o tipo de registro de entrada para o usuário (RFID ou biometria). O administrador deverá escolher a opção RFID.

&nbsp;&nbsp;&nbsp;&nbsp;Em seguida, o cartão será aproximado para cadastro, momento em que o ESP32 gerará um código HASH e o gravará no cartão. Esse código será então enviado via MQTT para a API, que, com os dados do usuário já cadastrados, registrará o HASH no banco de dados e relacionará o usuário cadastrado. Após o registro, uma confirmação será enviada para a dashboard, permitindo que o administrador visualize a conclusão do processo.

<div align="center">
<sub>Figura 41 - Diagrama UML - Visualização das Informações (caso de teste 05)</sub>  <br><br>
<img src="..\document\assets\diagramaUML\dashboard.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;Para verificar os dados de presença, o usuário deverá acessar a homepage e selecionar a opção "Dashboard", onde as informações serão exibidas. Para isso, ela realizará uma requisição à API, que buscará os dados no banco de dados e os retornará para serem exibidos ao usuário.

&nbsp;&nbsp;&nbsp;&nbsp;Essa seção reúne os casos de teste para o gerenciamento de controle de acesso, complementados por diagramas UML que ilustram os principais fluxos de operação. Essa combinação facilita a compreensão dos processos e garante que o sistema funcione de maneira integrada. Nestas imagens, podemos ter uma breve análise do protótipo físico de desenvolvimento. Ele apresenta características essenciais que permitem a funcionalidade e uma estrutura pretendida para o produto final.

<div align="center">
<sub>Figura 42 - Protótipo Fisíco</sub>  
<img src="..\document\assets\prototipo_1.jpg" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 43 - Protótipo Físico</sub>  
<img src="..\document\assets\prototipo_2.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

#### Documentação do código do protótipo físico

&nbsp;&nbsp;&nbsp;&nbsp; A princípio, é válido mencionar que o código do protótipo físico <a id="../src/firmware/main.ino">main.ino</a>. Porém, existe uma outra pasta, chamada Protótipo físico que possui o código mais avançado do projeto, porém ainda está em fase de testes e não está pronto para implementação.

&nbsp;&nbsp;&nbsp;&nbsp;Este sistema foi projetado para gerenciar o acesso por meio de autenticação biométrica e leitura de RFID, integrando componentes como LED RGB, buzzer, display LCD, conectividade WiFi e MQTT. A seguir, cada classe e função são explicadas.

**Classe LCDDisplay**

Gerencia a exibição de mensagens no display LCD e no monitor serial.

  - Construtor:

  `LCDDisplay(uint8_t address, uint8_t cols, uint8_t rows)`

  Configura o endereço e as dimensões do display LCD.

  - Funções:
      `void init()`: Inicializa o display e ativa o backlight.
      `void showMessage(const char* message)`: Exibe uma mensagem no display e no monitor serial.

**Classe MQTTConnection**

Gerencia a conexão e a comunicação via protocolo MQTT.

  - Construtor:

  `MQTTConnection(LCDDisplay& disp, WiFiClientSecure& secClient, PubSubClient& mqttCli)`

  Configura os objetos necessários para a conexão MQTT.

  - Funções:
      `void setup()`: Configura o cliente MQTT.
      `void reconnect()`: Tenta reconectar ao broker MQTT.
      `void sendMessage(const char* topic, const char* message)`: Publica uma mensagem em um tópico MQTT.
      Callback: Processa mensagens recebidas e altera o estado do sistema conforme o tópico.

**Classe WiFiConnection**

Gerencia a conexão à rede WiFi.

- Construtor:

`WiFiConnection(const char* ssid, const char* password, LCDDisplay& display)`

Configura os parâmetros da conexão WiFi.

- Funções:
    `void connect()`: Conecta à rede WiFi.
    `bool isConnected()`: Retorna o status da conexão.

**Classe LedRGB**

Controla um LED RGB para indicar estados do sistema.

- Construtor:

`LedRGB(int red, int green, int blue)`

Define os pinos para cada cor do LED.

- Funções:
    `void init()`: Configura os pinos como saída.
    `void setColor(bool red, bool green, bool blue)`: Define a cor do LED.

**Classe Buzzer**

Controla um buzzer para emitir alertas sonoros.

- Construtor:

`Buzzer(int pin)`

Define o pino do buzzer.

- Funções:
    `void init()`: Configura o pino como saída.
    `void beep(int duration = 100)`: Emite um sinal sonoro.

**Classe BiometricSensor**

Gerencia o sensor biométrico para autenticação.

- Construtor:

`BiometricSensor(HardwareSerial* serial, LCDDisplay& display)`

Configura o sensor biométrico e o display para feedback.

- Funções:
    `void init()`: Inicializa o sensor biométrico.
    `bool authenticate()`: Realiza a autenticação por impressão digital.

**Classe RFIDSensor**

Gerencia o sensor RFID para leitura de tags.

- Construtor: 

`RFIDSensor(uint8_t sda, uint8_t rst)`

Define os pinos SDA e RST do módulo RFID.

Funções:
    `void init()`: Inicializa o módulo RFID.
    `String readUID()`: Retorna o UID da tag RFID presente.

**Classe AccessSystem**

Integra todos os componentes do sistema de controle de acesso.

- Construtor: Configura os componentes com os pinos e parâmetros necessários.

- Funções:
    `void init()`: Inicializa todos os módulos do sistema.
    `void run()`: Executa o loop principal do sistema.

    - Lógica Interna:
        `handleCadastro()`: Gerencia o modo de cadastro.
        `handleAccess()`: Gerencia o acesso por biometria ou RFID.
        `processAccess(const char* message)`: Libera o acesso e emite sinais visuais e sonoros.

**Funções ESP-32**

`void setup()`: Inicializa o sistema.
`void loop()`: Executa o loop principal chamando system.run().


#### Fluxo do sistema

&nbsp;&nbsp;&nbsp;&nbsp;O sistema inicia conectando à rede WiFi e ao broker MQTT para garantir a comunicação com servidores remotos. Em seguida, ele permanece em estado de espera, monitorando interações com o sensor biométrico e o sensor RFID. Quando uma autenticação é realizada com sucesso, o sistema libera o acesso ativando um relé, sinalizando o evento com um LED verde e emitindo um alerta sonoro através do buzzer. Todas as ações, como tentativas de autenticação e concessões de acesso, são registradas e publicadas em tópicos MQTT para acompanhamento. Em modo de cadastro, o sistema permite registrar novas digitais ou tags RFID, integrando-as ao banco de dados de autenticação.

#### Conclusões Preliminares

&nbsp;&nbsp;&nbsp;&nbsp;Com base nos testes realizados no protótipo físico do projeto, é possível concluir que o sistema atende às exigências principais de um controle de acesso automatizado. Os resultados dos testes demonstram que o ESP32, os sensores biométricos, leitores RFID e a comunicação via Broker MQTT operam de forma integrada e com alta confiabilidade, tanto em cenários online quanto offline. Os casos de fallback para falha de Wi-Fi e de comunicação com o Broker MQTT foram executados com sucesso, garantindo a integridade dos registros e do funcionamento do sistema. Esses resultados sugerem que o protótipo está apto para ser implementado em ambientes reais com pequenas adaptações e refinamentos adicionais. A documentação do código, aliada aos diagramas UML, facilita a manutenção e a escalabilidade do sistema, reforçando seu potencial como uma solução para controle de frequência.

### 3.4.5. Protótipo Final do Projeto <a id="c3-4-5"></a>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção, são apresentados os casos de teste realizados para o protótipo final do projeto de controle de acesso utilizando ESP32, RFID e biometria. Os testes foram desenvolvidos com base nos diagramas UML e nos fluxos de operação documentados anteriormente. Cada caso de teste foi projetado para validar diferentes aspectos do sistema, incluindo acesso offline e online, cadastro de usuários, falhas de comunicação e atualizações de firmware. O objetivo é garantir que o sistema funcione eficientemente em todas as situações de uso.

| **#** | **Descrição**                                         | **Configuração do Ambiente**                         | **Ação do Usuário**                                              | **Resposta do Sistema**                                                                                                           |
|--------|------------------------------------------------------|------------------------------------------------------|------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| **01** | Acesso de um usuário com cartão RFID (Offline e Online) | ESP32 conectado ao leitor RFID e display LCD      | Aproximação de um cartão RFID cadastrado                         | **Offline:** LCD exibe "**Acesso liberado**", LED verde acende, buzzer emite som.<br>**Online:** Presença registrada no banco de dados. |
| **02** | Cadastro de um usuário                              | Dashboard conectada à API e banco de dados           | Inserção dos dados do usuário e registro de cartão RFID          | Cadastro confirmado na dashboard após envio e registro dos dados.                                                                |
| **03** | Visualização das informações de presença            | Dashboard conectada à API e banco de dados           | Solicitação de visualização dos dados na dashboard               | Dados de presença exibidos corretamente na dashboard.                                                                            |
| **04** | Acesso negado com cartão RFID não cadastrado        | ESP32 conectado ao leitor RFID                       | Aproximação de um cartão RFID não cadastrado                     | LCD exibe "**Acesso negado**", LED vermelho acende.                                                                               |
| **05** | Cadastro de um novo cartão RFID para usuário        | Dashboard conectada ao ESP32 e Broker MQTT           | Seleção de opção de cadastro de cartão RFID na dashboard         | Confirmação do cadastro exibida na dashboard.                                                                                    |
| **06** | Falha de conexão com o Broker MQTT                  | ESP32 configurado para fallback local                | Aproximação de cartão RFID com falha de conexão MQTT             | Dados armazenados localmente e reenviados após reconexão.                                                                        |
| **07** | Atualização de firmware do ESP32                    | ESP32 conectado ao Wi-Fi e Broker MQTT               | Início de atualização do firmware                                | ESP32 reinicia e retorna à operação normal após a atualização.                                                                   |
| **08** | Tentativa de acesso com digital biométrica inválida | ESP32 conectado ao sensor biométrico e LCD           | Leitura de uma digital não cadastrada                           | LCD exibe "**Digital não cadastrada**", LED vermelho acende.                                                                     |
| **09** | Reenvio automático após falha na comunicação MQTT   | ESP32 configurado para fallback                      | Aproximação de cartão após falha temporária na comunicação       | Dados armazenados localmente e enviados automaticamente após reconexão.                                                         |
| **10** | Criação de um novo evento                           | Dashboard conectada à API e banco de dados           | Inserção dos dados para a criação do evento                      | Mensagem de sucesso aparece para o usuário.                                                                                      |

&nbsp;&nbsp;&nbsp;&nbsp;Os casos de teste apresentados demonstram que o protótipo final do projeto é capaz de atender às necessidades de controle de acesso em diferentes cenários, tanto em condições normais quanto em situações adversas, como falhas de conexão. As respostas esperadas e recebidas do sistema mostram que os principais componentes estão integrados corretamente e respondem de forma apropriada às interações dos usuários. Abaixo temos os diagramas UMLs, que apresentam o fluxo das informações, facilitando a visualização.

<div align="center">
<sub>Figura 44 - Diagrama UML - Tentativa de Acesso com um Cartão Não Cadastrado (caso de teste 04)</sub>  <br><br>
<img src="..\document\assets\diagramaUML\acesso_negado.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;O usuário aproxima um cartão não cadastrado do sensor. O leitor identifica o código presente no cartão e o envia ao ESP32, que verifica se o código está registrado. Como o código não está cadastrado, o microcontrolador informa que o acesso foi negado, exibindo uma mensagem no display, acendendo o LED na cor vermelha e emitindo um som mais prolongado e grave pelo buzzer.

<div align="center">
<sub>Figura 45 - Diagrama UML - Criação de Evento (caso de teste 10)</sub>  <br><br>
<img src="..\document\assets\diagramaUML\criacao_evento.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;O usuário acessa a página de criação de eventos na dashboard, onde haverá campos para inserir os dados do evento. Após essa etapa ser concluída, a dashboard enviará os dados para a API, que registrará as informações diretamente no banco de dados. Em seguida, será exibida para o usuário uma mensagem: "Evento criado com sucesso!".

&nbsp;&nbsp;&nbsp;&nbsp;A seguir, são apresentadas as telas desenvolvidas para o sistema RedLock do Instituto Apontar. Cada tela representa uma funcionalidade específica, destacando as principais ações disponíveis para os usuários e administradores do sistema.

<div align="center">
<sub>Figura 46 - Tela de Login</sub>  <br><br> 
<img src="..\document\assets\dashboard\tela_login.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 47 - Tela Inicial</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_home.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 48 - Adicionar Usuário</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_addusuario.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 49 - Registro de Frequências</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_dash.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 50 - Cadastro de Evento</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_evento.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 51 - Gerenciar Usuários</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_gerusuario.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 52 - Relatórios e Dashboards</sub>  <br><br>
<img src="..\document\assets\dashboard\tela_prof.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

&nbsp;&nbsp;&nbsp;&nbsp;A seguir, são apresentadas as imagens do protótipo físico do sistema. Este protótipo integra componentes de hardware responsáveis pela autenticação e controle de acesso, incluindo o sensor biométrico, display LCD e o microcontrolador ESP32. As imagens ilustram os módulos de reconhecimento e cadastro. Estas imagens demonstram a estrutura técnica e a interação entre os componentes do sistema físico.

<div align="center">
<sub>Figura 53 - Cadastro da Biometria no sensor</sub>  <br><br>
<img src="..\document\assets\biometria\id_cadastro.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 54 - Biometria Reconhecida pelo sensor</sub>  <br><br>
<img src="..\document\assets\biometria\digital_reconhecida.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<div align="center">
<sub>Figura 55 - Biometria não Reconhecida pelo sensor</sub>  <br><br>
<img src="..\document\assets\biometria\digital_Nreconhecida.png" width="100%">  
<sup>Fonte: Material produzido pelo grupo Exodia (2024)</sup>
</div>

<br>

&nbsp;&nbsp;&nbsp;&nbsp;Por fim, segue um vídeo demonstrativo de cada funcionalidade do nosso projeto.


[Link para o vídeo de demonstração do funcionamento do projeto](https://drive.google.com/drive/folders/1-I6ceLT4buagPac3aFtw8YtwmXmyKkds)

&nbsp;&nbsp;&nbsp;&nbsp;O protótipo final do projeto RedLock demonstrou ser eficaz no controle de acesso por meio da biometria, integrando corretamente os componentes de hardware e software, como o ESP32, MQTT Broker e a API. Os casos de teste validaram o funcionamento em cenários normais e adversos, incluindo falhas de conexão e atualizações de firmware, garantindo sincronização de dados e operação offline. As telas do front-end oferecem uma interface intuitiva para o gerenciamento de usuários e eventos, enquanto o protótipo físico executa comandos com rapidez, fornecendo feedback visual e sonoro adequado. Com base nesses resultados, o projeto atende plenamente aos requisitos funcionais e não funcionais, estando pronto para implementação no Instituto Apontar com segurança e confiabilidade.

### 3.4.6. Testes de usabilidade <a id="c3-4-6"> </a>

&nbsp;&nbsp;&nbsp;&nbsp;Nesta seção está a documentação dos testes realizados, abrangendo o painel de controle web e o protótipo físico. Foram avaliadas funcionalidades como registro de usuários, cadastro de eventos, filtragem de dados na dashboard e acesso via biometria. Os testers foram alunos da Turma 13, representando coordenadores, professores e alunos, permitindo identificar possíveis problemas e coletar feedback sobre a usabilidade. Os resultados destacam os aspectos funcionais, com recomendações para correções e melhorias que visam aprimorar a experiência do usuário.

#### 3.4.6.1 Contexto dos Testes <a id="3-4-6-1"> </a>

**Local:**  
Os testes foram realizados no ateliê 04, simulando cenários de uso do protótipo e do painel de controle. 

**Data:**  
Os testes foram conduzidos no dia 2 de dezembro de 2024.

**Perfil do Público:**  
- **Coordenadores:** Usuários com perfil administrativo, responsáveis por gerenciar o sistema, cadastrar eventos e analisar dados. Eles têm experiência moderada com sistemas administrativos.  
- **Professores:** Usuários com perfil intermediário, utilizando o sistema para apoio ao gerenciamento de eventos e monitoramento de alunos.  
- **Alunos:** Usuários que interagiram com os dispositivos para uso biométrico. A maioria possui familiaridade limitada com tecnologia, o que destaca possíveis falhas na usabilidade.

**Parâmetros de Aplicação:**  
&nbsp;&nbsp;&nbsp;&nbsp;Cada funcionalidade foi testada com pelo menos quatro usuários.  

- Os cenários foram divididos em:
  - **Painel Web:** Testes de registro de usuários, eventos e análise de dados na dashboard.
  - **Dispositivos Físicos:** Testes de cadastro biométrico e leitura da biometria cadastrada.  

&nbsp;&nbsp;&nbsp;&nbsp;Foi utilizada uma abordagem de observação ativa, em que os testers relataram dificuldades durante as tarefas, e os resultados foram anotados para análise.
<br></br>

#### 3.4.6.2 Problemas Detectados e Resultados Obtidos <a id="3-4-6-2"> </a>

**Problemas Gerais**

**Feedback insuficiente ao usuário:**  
  - Falta de animações ou indicadores visuais de carregamento, causando dúvidas sobre o sucesso ou falha de certas ações. Exemplo: cadastro de eventos ou usuários.  
  - Mensagens de erro genéricas ou inexistentes.

**Dificuldade no uso de dispositivos biométricos:**  
  - Problemas na leitura biométrica em 50% dos testes. Ao colocar o dedo no leitor, ele não reconhece corretamente as digitais, impossibilitando o cadastro.  
  - Observou-se que a função de leitura funciona, mas pode haver inconsistências no código para habilitar a captura dentro do tempo definido pela função.  

**Interface da Dashboard:**  
  - Contraste insuficiente para alguns elementos de interface, afetando a acessibilidade.  
  - Falta de filtros adaptáveis, levando à exibição de opções irrelevantes para o contexto.  
  - Ausência de paginação para grandes volumes de dados.

**Resultados Tabulados por Tarefa**

**Registrar Usuário**  
  - Sucesso Geral: 100%.  
  - Dificuldade Notada: Ausência de indicador de carregamento ou mensagem clara de confirmação.  

**Cadastrar Evento**  
  - Sucesso Geral: 75%.  
  - Dificuldade Notada: Um tester não conseguiu concluir devido à ausência de mensagem de erro detalhada.  

**Filtrar Dados na Dashboard**  
  - Sucesso Geral: 100%.  
  - Feedback: A dashboard ficou muito boa, mas é necessário melhorar os elementos visuais descritos pelos testers, como o contraste e a adaptação de filtros.  

**Cadastro Biométrico**  
  - Sucesso Geral: 50%.  
  - Dificuldade Notada: Problemas no reconhecimento das digitais, possivelmente causados por inconsistências no código que gerencia a leitura no tempo correto.

**Reconhecimento Biométrico**  
  - Sucesso Geral: 75%.  
  - Observação: Falhas causadas por digitais não cadastradas previamente devido à inconsistência no processo inicial.
<br></br>

#### 3.4.6.3 Próximos Passos e Planejamento de Correção <a id="3-4-6-3"> </a>

**Correções Prioritárias (Gravidade Alta)**

**Cadastro Biométrico:**  
  - Melhoria Técnica: Otimizar o código responsável pela leitura biométrica, garantindo que o sensor capture digitais no tempo definido pela função.  
  - Interface: Adicionar mensagens claras de orientação, incluindo feedback sobre a leitura, para informar se o sensor está detectando corretamente.

**Feedback no Sistema:**  
  - Mensagem de Confirmação: Implementar notificações de sucesso após ações como registro de usuários ou eventos.  
  - Mensagens de Erro Detalhadas: Exibir erros específicos, como "Data inválida" ou "Conexão instável".  

**Melhorias a Médio Prazo (Gravidade Média)**

**Dashboard:**  
  - Melhorar o contraste para atender padrões de acessibilidade.  
  - Adicionar filtros dinâmicos que adaptem as opções com base na seleção inicial.  
  - Implementar paginação para dados volumosos.  

**Implementações Futuras (Gravidade Baixa)**

**Melhorias na UX (Experiência do Usuário):**  
  - Adicionar indicadores de carregamento para todas as ações críticas.  
  - Criar um guia interativo ou tutorial no sistema para novos usuários.
<br></br>

**Plano de Ação**

- **Fase 1 (1° semana):** Corrigir feedback visual e mensagens de erro em todo o sistema.  
- **Fase 2 (2° semana):** Ajustar a lógica de leitura do leitor biométrico e otimizar o código para garantir o registro de digitais.  
- **Fase 3 (3° semana):** Implementar melhorias na dashboard, como paginação e contraste. Além disso, conduzir novos testes no final para validar as melhorias, coletar feedback adicional e ajustar detalhes finais.

&nbsp;&nbsp;&nbsp;&nbsp;Os testes demonstraram um sistema funcional, mas com problemas de usabilidade e inconsistências que afetam a experiência do usuário. As melhorias propostas visam resolver os problemas mais críticos, priorizando a clareza do feedback, a funcionalidade do cadastro biométrico e a usabilidade geral. A implementação de correções e a realização de novos testes são importantes para garantir uma utilização satisfatória do sistema pelos usuários.


## <a name="c4"></a>4. Conclusões e Recomendações

&nbsp;&nbsp;&nbsp;&nbsp;O projeto RedLock, desenvolvido pelo grupo Exodia em colaboração com o Instituto Apontar, apresentou resultados significativos ao resolver os desafios relacionados ao controle de acesso e à gestão de frequência na instituição. A solução implementada utiliza tecnologias de IoT, eliminando processos manuais e propensos a erros, garantindo facilidade e eficiência no registro de entradas e saídas de alunos, colaboradores e visitantes. Essa automação trouxe um aumento considerável na segurança, pois permite que apenas pessoas autorizadas tenham acesso às dependências do Instituto.

&nbsp;&nbsp;&nbsp;&nbsp;A centralização dos dados no banco de dados integrado e a sincronização com o painel de controle facilitam a consulta e análise das informações de frequência. A interface visual desenvolvida permite a visualização simplificada dos registros e a geração de relatórios com filtros disponíveis para a análise, otimizando o tempo dos gestores e possibilitando uma tomada de decisão informada. A solução desenvolvida ajudará a reduzir a carga de trabalho operacional, além de um aumento na transparência e no controle sobre o fluxo de pessoas dentro da instituição.

Recomendamos que o Instituto Apontar adote as seguintes práticas para garantir uma solução em pleno estado de funcionamento:

**Treinamento Contínuo:**
- É essencial para que colaboradores e gestores se mantenham atualizados com as funcionalidades e possíveis atualizações do sistema. A utilização do manual de instruções, vídeos tutoriais e nosso material pedagógico ajudará na capacitação e servirá como material de referência para novos usuários. 

**Manutenção Preventiva:** 
- Manutenção periódica dos dispositivos de hardware, como os sensores biométricos, leitores RFID e servidores, ajudará a evitar falhas e interrupções no serviço.

**Revisão da Conformidade com a LGPD:**
- Revisar e atualizar a política de privacidade regularmente para assegurar o cumprimento da Lei Geral de Proteção de Dados (LGPD), especialmente em relação à coleta e armazenamento de dados sensíveis, como informações biométricas. Realizar auditorias periódicas para reforçar a segurança e a integridade dos dados.

**Implementação de Chaves de Criptografia:**
- A comunicação entre a tag RFID e os leitores pode ser protegida usando chaves criptográficas. A tag e o leitor devem compartilhar uma chave de criptografia para criptografar e descriptografar os dados dos usuários.

**Proteção contra Ataques:**
- Considerar medidas de segurança contra ataques como replay attacks, man-in-the-middle (MITM) e outros ataques de criptoanálise. A implementação de hash codes para verificar a integridade dos dados pode ajudar a detectar possíveis modificações não autorizadas.

&nbsp;&nbsp;&nbsp;&nbsp;Em conclusão, a implementação do sistema RedLock proporciona ao Instituto Apontar uma ferramenta prática e confiável para o controle de acesso e gestão de frequência. Essa modernização não apenas solucionará problemas operacionais existentes, mas também abrirá caminho para uma gestão mais segura e uma solução importante aos responsáveis do instituto. A continuidade desse projeto e a adoção das recomendações sugeridas garantirão que os benefícios obtidos sejam sustentáveis e possam evoluir conforme as necessidades futuras da instituição.

## <a name="c5"></a>5. Referências

[1] Instituto Apontar. *Site oficial do Instituto Apontar*. Disponível em: https://institutoapontar.org.br/. Acesso em: 20/10/2024.

[2] Gerando Falcões. *Site oficial da ONG Gerando Falcões*. Disponível em: https://gerandofalcoes.com/quem-somos/. Acesso em: 20/10/2024.

[3] Instituto Rogério Steinberg. *Site oficial do Instituto Rogério Steinberg*. Disponível em: https://irs.org.br/o-instituto/. Acesso em: 20/10/2024.

[4] Governo Federal. *Lei Geral de Proteção de Dados Pessoais (LGPD)*. Disponível em: https://www.planalto.gov.br/ccivil_03/_ato2015-2018/2018/lei/l13709.htm. Acesso em: 10/11/2024.

[5] MALDONADO, Viviane Nóbrega. *LGPD – Teoria e Prática*. Editora Forense, 2020. Disponível em: https://www.editoraforense.com.br/produto/lgpd-teoria-e-pratica/. Acesso em: 24/10/2024.

[6] CASAROTTO, Camila. *As 5 forças de Porter: quais são elas e como entender o conjunto de fatores que influenciam no sucesso do seu negócio?*. Rockcontent, 2020. Disponível em: https://rockcontent.com/br/blog/5-forcas-de-porter/#:~:text=As%205%20Forças%20de%20Porter%20são%20um%20framework%20de%20análise,influenciam%20o%20sucesso%20dos%20negócios. Acesso em: 17/11/2024.

[7] Circuitar. *Setup & Loop*. Disponível em: https://www.circuitar.com.br/projetos/setup-loop/index.html. Acesso em: 24/10/2024.

[8] McEWEN, Adrian; CASSIMALLY, Hakim. *Designing the Internet of Things*. John Wiley & Sons, 2013. Disponível em: https://www.wiley.com/en-us/Designing+the+Internet+of+Things-p-9781118430620. Acesso em: 05/11/2024.

[9] HOPPER, David. *MQTT and CoAP for IoT: Comparison and Performance Evaluation*. Disponível em: https://iot.eecs.berkeley.edu/articles/mqtt-vs-coap-performance. Acesso em: 07/11/2024.

[10] HiveMQ. *Blog sobre MQTT e IoT*. Disponível em: https://www.hivemq.com/blog/. Acesso em: 07/11/2024.

[11] KRUG, Steve. *Don’t Make Me Think: A Common Sense Approach to Web Usability*. 3. ed. New Riders, 2014. Disponível em: https://www.sensible.com/dmmt.html. Acesso em: 12/11/2024.

[14] SUTHERLAND, Jeff. *Scrum: The Art of Doing Twice the Work in Half the Time*. Random House Business, 2014. Disponível em: https://www.randomhouse.com/book/231538/scrum-by-jeff-sutherland. Acesso em: 08/12/2024.
