#include <iostream>

#include "VertigoRenderer.h"
#include "twodee/NField.h"
#include "twodee/QVector4.h"
#include "twodee/QMath.h"
#include "twodee/UtilitiesOpenGL.h"

using namespace td;

/* ------------------------------------------------------------------------- */

VertigoRenderer::VertigoRenderer() :
  attributes(NULL),
  array(NULL),
  program(NULL) {
}

/* ------------------------------------------------------------------------- */

VertigoRenderer::~VertigoRenderer() {
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::initializeGL() {
  glClearColor(100 / 255.0f, 149 / 255.0f, 237 / 255.0f, 1.0f);

  std::string vertex_source =
    "#version 410\n"
    "\n"
    "uniform mat4 projection;\n"
    "uniform mat4 modelview;\n"
    "\n"
    "in vec3 position;\n"
    "\n"
    "void main() {\n"
    "  gl_Position = projection * modelview * vec4(position, 1.0);\n"
    "}\n";

  std::string fragment_source =
    "#version 410\n"
    "\n"
    "out vec4 frag_color;\n"
    "\n"
    "void main() {\n"
    "  frag_color = vec4(1.0);\n"
    "}\n";

  program = ShaderProgram::FromSource(vertex_source, fragment_source);
  OpenGL::CheckError("after program");

  OpenGL::CheckError("after array");
  mesh = new Trimesh(path);

  attributes = new VertexAttributes();
  attributes->AddAttribute("position", mesh->GetVertexCount(), 3, mesh->GetPositions());
  attributes->AddAttribute("normal", mesh->GetVertexCount(), 3, mesh->GetNormals());
  attributes->AddIndices(mesh->GetFaceCount() * 3, mesh->GetFaces());

  array = new VertexArray(*program, *attributes);
  OpenGL::CheckError("after initialize");

  modelview = QMatrix4<float>(1.0f);
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::resize(int width, int height) {
  glViewport(0, 0, width, height);  

  float window_aspect = width / (float) height;

  projection = QMatrix4<float>::GetPerspective(45.0f, window_aspect, 0.1f, 1000.0f);
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  program->Bind();
  program->SetUniform("projection", projection);
  program->SetUniform("modelview", modelview);
  array->Bind();
  array->DrawIndexed(GL_TRIANGLES);
  array->Unbind();
  program->Unbind();

  OpenGL::CheckError("after render");
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::leftMouseDownAt(int x, int y) {
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::leftMouseDraggedTo(int x, int y) {
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::leftMouseUpAt(int x, int y) {
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::scroll(int nTicks) {
  if (nTicks != 0) {
    float factor = 1 + nTicks / 100.0f;;
    modelview = QMatrix4<float>::GetScale(factor, factor, 1.0f) * modelview;
  }
}

/* ------------------------------------------------------------------------- */

void VertigoRenderer::load(const std::string &path) {
  this->path = path;
}

/* ------------------------------------------------------------------------- */

