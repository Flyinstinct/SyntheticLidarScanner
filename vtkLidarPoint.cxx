#include "vtkLidarPoint.h"
#include "vtkRay.h"

#include "vtkSmartPointer.h"
#include "vtkObjectFactory.h" //for new() macro

vtkCxxRevisionMacro(vtkLidarPoint, "$Revision: 1.1 $");
vtkStandardNewMacro(vtkLidarPoint);

vtkLidarPoint::vtkLidarPoint()
{
	//until specified, this LidarPoint is invalid
  this->Hit = false;
  this->Ray = NULL;
}

vtkLidarPoint::~vtkLidarPoint() 
{
  if(this->Ray)
    this->Ray->Delete();
}

vtkCxxSetObjectMacro(vtkLidarPoint, Ray, vtkRay);


double* vtkLidarPoint::GetNormal()
{
	//there is only a normal if this is a valid LidarPoint
	if(this->Hit)
    {
		return Normal;
    }
	else
    {
		return NULL;
    }
}

void vtkLidarPoint::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  
	//if the LidarPoint is valid, print its information
	if(this->Hit)
	  {
		os << "Coordinate: " << Coordinate[0] << " " << Coordinate[1] << " " << Coordinate[2] << vtkstd::endl
			<< "Ray: " << *Ray << vtkstd::endl
			<< "Normal: " << Normal[0] << " " << Normal[1] << " " << Normal[2] << vtkstd::endl;
	  }
	else
	  {
		os << "Invalid!" << vtkstd::endl;
	  }

}
