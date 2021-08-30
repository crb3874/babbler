#pragma once

// Used as base -- ADKernelGrad
#include "ADKernelGrad.h"

// Kernel for k/mu grad_test grad_u in weak form of Pressure equation.
class DarcyPressure : public ADKernelGrad
{
public:
    
    static InputParameters validParams();
    DarcyPressure(const InputParameters & parameters);
    
protected:
    // Override precomputeQpResidual;
    virtual ADRealVectorValue precomputeQpResidual() override;
    
    // Variable storing physical constants (k, mu) -- given by inputs. Written by constructor.
    const ADMaterialProperty<Real> & _permeability;
    const ADMaterialProperty<Real> & _viscosity;
};
