#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "Actor.h"
#include "ActorGL.h"

namespace evolver {

  ActorGL::ActorGL (void) {
    this->actor = NULL;
  }

  ActorGL::~ActorGL (void) {
    delete this->actor;
  }

  ActorGL::ActorGL (const ActorGL &original) {
    *(this->actor) = *(original.actor);
  }

  ActorGL &ActorGL::operator= (const ActorGL &original) {
    if (this != &original) {
      *(this->actor) = *(original.actor);
    }

    return *this;
  }

  Actor *ActorGL::getActor () {
    return this->actor;
  }

  void ActorGL::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void ActorGL::draw (void) {   
    glColor3fv(ACTOR_COLOR3F);

    glBegin(GL_QUADS);
	    glVertex2i(this->actor->getOrigin()->getX(), 
		       this->actor->getOrigin()->getY());
	    glVertex2i(this->actor->getOrigin()->getX(),
		       (this->actor->getOrigin()->getY() + 
			ACTOR_SIZE));
	    glVertex2i((this->actor->getOrigin()->getX() + 
			ACTOR_SIZE), 
		       (this->actor->getOrigin()->getY() + 
			ACTOR_SIZE));
	    glVertex2i((this->actor->getOrigin()->getX() + 
			ACTOR_SIZE), 
		       this->actor->getOrigin()->getY());    
    glEnd();

    return;
  }

}
