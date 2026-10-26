#include <algorithm>
#include <cassert>

#include "scenegraph.h"

using namespace std;

bool SgTransformNode::accept(SgNodeVisitor &visitor) {
    if (!visitor.visit(*this))
        return false;
    for (int i = 0, n = children_.size(); i < n; ++i) {
        if (!children_[i]->accept(visitor))
            return false;
    }
    return visitor.postVisit(*this);
}

void SgTransformNode::addChild(shared_ptr<SgNode> child) {
    children_.push_back(child);
}

void SgTransformNode::removeChild(shared_ptr<SgNode> child) {
    children_.erase(find(children_.begin(), children_.end(), child));
}

bool SgShapeNode::accept(SgNodeVisitor &visitor) {
    if (!visitor.visit(*this))
        return false;
    return visitor.postVisit(*this);
}

class RbtAccumVisitor : public SgNodeVisitor {
  protected:
    vector<RigTForm> rbtStack_;
    SgTransformNode &target_;
    bool found_;

  public:
    RbtAccumVisitor(SgTransformNode &target) : target_(target), found_(false) {}

    const RigTForm getAccumulatedRbt(int offsetFromStackTop = 0) {
        // TODO, currently returns a dummy variable
        return RigTForm();
    }

    virtual bool visit(SgTransformNode &node) {
        // TODO, currently always return true
        return true;
    }

    virtual bool postVisit(SgTransformNode &node) {
        // TODO, currently always return true
        return true;
    }
};

RigTForm getPathAccumRbt(shared_ptr<SgTransformNode> source,
                         shared_ptr<SgTransformNode> destination,
                         int offsetFromDestination) {

    // Ensure source and destination aren't null ptrs
    assert(source);
    assert(destination);

    RbtAccumVisitor accum(*destination);
    source->accept(accum);
    return accum.getAccumulatedRbt(offsetFromDestination);
}
