string description = "Basic 2d sprite";

//------------------------------------
float4x4 worldViewProj : WorldViewProjection;
int frameNumber : FrameNumber; 
float frameWidth : FrameWidth;

texture colorTexture : Texture0
<
	string ResourceName = "photo.dds";
>;

float4 materialDiffuse : Color
<
    string UIWidget = "Surface Color";
    string Space = "material";
> = {1.0f, 1.0f, 1.0f, 1.0f};

float4 white = {1.0f, 1.0f, 1.0f, 1.0f};

//------------------------------------
struct vertexInput {
    float3 position				: POSITION;
};

struct vertexOutput {
    float4 hPosition		: POSITION;
    float2 texCoordDiffuse	: TEXCOORD0;
    float2 depth			: TEXCOORD1;
};


struct pixelOutput {
    float4 color		: COLOR;
    float depth	: DEPTH;
};


struct pixelOutputSimple {
    float4 color		: COLOR;
};

//------------------------------------
vertexOutput VS_TransformAndFrame(vertexInput IN) 
{
    vertexOutput OUT;
    OUT.hPosition = mul( float4(IN.position.xyz , 1.0) , worldViewProj);
    OUT.texCoordDiffuse.xy = (IN.position.xy + 0.5);
    OUT.texCoordDiffuse.x = OUT.texCoordDiffuse.x*frameWidth+frameWidth*frameNumber;
    OUT.texCoordDiffuse.y = 1.0f - OUT.texCoordDiffuse.y;
    OUT.depth.x = OUT.hPosition.z;
    OUT.depth.y = OUT.hPosition.w;
    return OUT;
}


//------------------------------------
sampler TextureSampler = sampler_state 
{
    texture = <colorTexture>;
    AddressU  = CLAMP;        
    AddressV  = CLAMP;
    AddressW  = CLAMP;
    MIPFILTER = POINT;
    MINFILTER = POINT;
    MAGFILTER = POINT;
};

pixelOutputSimple PS_Simple( vertexOutput IN)
{
    pixelOutputSimple OUT;
  float4 diffuseTexture = tex2D( TextureSampler, IN.texCoordDiffuse );
  if(diffuseTexture.x >= 0.99 && diffuseTexture.y <= 0.01 && diffuseTexture.z >= 0.99)
  	clip(-1);
  OUT.color = materialDiffuse * diffuseTexture;
  OUT.color.a = 1;
  return OUT;
}

//-----------------------------------
pixelOutput PS_PerPixel( vertexOutput IN) 
{

    pixelOutput OUT;
  float4 diffuseTexture = tex2D( TextureSampler, IN.texCoordDiffuse );
  if(diffuseTexture.x >= 0.99 && diffuseTexture.y <= 0.01 && diffuseTexture.z >= 0.99)
  	clip(-1);
  OUT.color = materialDiffuse * diffuseTexture;
  OUT.color.a = 1;
  OUT.depth = (IN.depth.x/IN.depth.y) + -0.01*(diffuseTexture.a - 0.5);
  return OUT;
}

//float4 PS_white( vertexOutput IN): COLOR0
//{
//  return white;
//}

//-----------------------------------
technique q0_p0_main
{
    pass p0 
    {		
		VertexShader = compile vs_2_0 VS_TransformAndFrame();
		PixelShader  = compile ps_2_0 PS_Simple();
    }
}

technique q1_p0_main
{
    pass p0 
    {		
		VertexShader = compile vs_2_0 VS_TransformAndFrame();
		PixelShader  = compile ps_2_0 PS_PerPixel();
    }
}