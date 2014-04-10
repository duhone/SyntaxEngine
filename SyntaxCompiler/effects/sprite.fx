string description = "Basic 2d sprite";

//------------------------------------
float4x4 worldViewProj : WorldViewProjection;
int frameNumber : FrameNumber; 
float frameWidth : FrameWidth;
float4 lights[8] : LightSet;

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
};


//------------------------------------
vertexOutput VS_TransformAndFrame(vertexInput IN) 
{
    vertexOutput OUT;
    OUT.hPosition = mul( float4(IN.position.xyz , 1.0) , worldViewProj);
    OUT.texCoordDiffuse.xy = (IN.position.xy + 0.5);
    OUT.texCoordDiffuse.x = OUT.texCoordDiffuse.x*frameWidth+frameWidth*frameNumber;
    return OUT;
}


//------------------------------------
sampler TextureSampler = sampler_state 
{
    texture = <colorTexture>;
    AddressU  = CLAMP;        
    AddressV  = CLAMP;
    AddressW  = CLAMP;
    MIPFILTER = LINEAR;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};


//-----------------------------------
float4 PS_Sample( vertexOutput IN): COLOR
{
  float4 diffuseTexture = tex2D( TextureSampler, IN.texCoordDiffuse );
  return materialDiffuse * diffuseTexture;
}

//-----------------------------------
technique q0_p0_main
{
    pass p0 
    {		
		VertexShader = compile vs_2_0 VS_TransformAndFrame();
		PixelShader  = compile ps_2_0 PS_Sample();
    }
}