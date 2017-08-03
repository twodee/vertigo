#ifndef CUADROSRENDERER_H
#define CUADROSRENDERER_H

#include <string>

#include "twodee/Configuration.h"

#include "twodee/NField.h"
#include "twodee/QMatrix4.h"
#include "twodee/QVector2.h"
#include "twodee/ShaderProgram.h"
#include "twodee/Trimesh.h"
#include "twodee/VertexAttributes.h"
#include "twodee/VertexArray.h"

class VertigoRenderer {
  public:
    VertigoRenderer();
    ~VertigoRenderer();

    void render();
    void resize(int width, int height);
    void initializeGL();

    void leftMouseDownAt(int x, int y);
    void leftMouseDraggedTo(int x, int y);
    void leftMouseUpAt(int x, int y);
    void scroll(int nTicks);

    void load(const std::string &path);

  private:
    td::Trimesh *mesh;
    std::string path;

    td::VertexAttributes *attributes;
    td::VertexArray *array;
    td::ShaderProgram *program;

    td::QMatrix4<float> projection;
    td::QMatrix4<float> modelview;
    td::QVector2<int> mouse_at;
};

#endif
