/************************************************************************************************************************************************
* Implementar a renderiza��o da cena de exemplo utilizando sombra projetada e gera��o de billboard no geometry shader.
**** 1- Criar geometria para representar o objeto do �ch�o" (associar uma textura coerente). Objeto pode representado apenas com 2 tri�ngulos
**** 2- Desenhar objeto do ch�o com um shader program espec�fico. Usar uma defini��o de proje��o em perspectiva.
**** 3- Parametrizar um ponto como geometria para gerar os v�rtices do ret�ngulo do billboard. Os v�rtices gerados podem predefinidos
**** (o que facilita para c�lculo de sombra projetada no fragment shader do objeto do ch�o) no geometry shader.
**** N�o esque�a de associar mapeamento de textura para cada v�rtice emitido no geometry shader.
**** 4- Desenhar objeto do billboard da �rvore utilizando um textura adequada, com transpar�ncia.
**** 5- Alterar fragment shader do objeto do ch�o para considerar o desenho de ponto de sombra:
**** cada fragmento deve testar a colis�o de um raio que vai para a fonte de luz com o ret�ngulo do billboard da �rvore; caso exista colis�o,
**** o ponto ser� desenhado com a cor da textura * o alfa da coordenada relativa de textura da �rvore:
**** �
**** P = colisaoBillboard(fragPos, light, billboardRect);
**** c = texture(chao, vt);
****  frag_color = c * (1 - texture(arvore, P).a * 0.6);
****  �
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
		
		// Limpeza Padr�o
		glfwSwapBuffers(render->getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}


// -------------------------------- �rea de Inputs e Callbacks -------------------------------- //

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
