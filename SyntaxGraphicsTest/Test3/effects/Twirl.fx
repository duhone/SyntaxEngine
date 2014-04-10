string description = "Basic 2d sprite";

//------------------------------------
float4x4 worldViewProj : WorldViewProjection;
float4 angle : Angle;

texture colorTexture : Texture0
<
	string ResourceName = "photo.dds";
>;

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
    OUT.texCoordDiffuse.xy = IN.position.xy;
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
  float z = length(IN.texCoordDiffuse.xy);
  float theta = atan2(IN.texCoordDiffuse.x,IN.texCoordDiffuse.y)+(3.14/2);
  float2 tex;
  tex.x = z*cos(theta+angle.x*z)+0.5;
  tex.y = z*sin(theta+angle.x*z)+0.5;
  tex.y = 1.0f - tex.y;
  float4 diffuseTexture = tex2D( TextureSampler, tex );
  return diffuseTexture;
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
		PixelShader  = compile ps_2_0 PS_Sample();
    }
}
