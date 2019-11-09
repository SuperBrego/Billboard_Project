/************************************************************************************************************************************************
* Implementar a renderização da cena de exemplo utilizando sombra projetada e geração de billboard no geometry shader.
**** 1- Criar geometria para representar o objeto do “chão" (associar uma textura coerente). Objeto pode representado apenas com 2 triângulos
**** 2- Desenhar objeto do chão com um shader program específico. Usar uma definição de projeção em perspectiva.
**** 3- Parametrizar um ponto como geometria para gerar os vértices do retângulo do billboard. Os vértices gerados podem predefinidos
**** (o que facilita para cálculo de sombra projetada no fragment shader do objeto do chão) no geometry shader.
**** Não esqueça de associar mapeamento de textura para cada vértice emitido no geometry shader.
**** 4- Desenhar objeto do billboard da árvore utilizando um textura adequada, com transparência.
**** 5- Alterar fragment shader do objeto do chão para considerar o desenho de ponto de sombra:
**** cada fragmento deve testar a colisão de um raio que vai para a fonte de luz com o retângulo do billboard da árvore; caso exista colisão,
**** o ponto será desenhado com a cor da textura * o alfa da coordenada relativa de textura da árvore:
**** …
**** P = colisaoBillboard(fragPos, light, billboardRect);
**** c = texture(chao, vt);
****  frag_color = c * (1 - texture(arvore, P).a * 0.6);
****  …
*************************************************************************************************************************************************/


// ----- External Libraries ----- //
#include <GLFW/glfw3.h>

// ----- Project Headers ----- //
#include "Render.h"
#include "DataCut.h"

// ----- Callback Functions ----- //
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// ----- Global Variables ----- //
DataCut* data;
Render* render;

// -------------------------------- //
int main() {
	
	data = new DataCut();

	render = new Render(800,400);
	render->createWindow();

	// Redimensionamento da Tela.
	glfwSetFramebufferSizeCallback(render->getWindow(), framebuffer_size_callback);
	glfwSetKeyCallback(render->getWindow(), key_callback);


	while (!glfwWindowShouldClose(render->getWindow())) {
		
		// Cores de Fundo
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Processamento
		
		// Limpeza Padrão
		glfwSwapBuffers(render->getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}


// -------------------------------- Área de Inputs e Callbacks -------------------------------- //

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
